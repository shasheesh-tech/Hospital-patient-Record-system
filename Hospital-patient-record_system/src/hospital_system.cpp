#include "HospitalSystem.h"
#include "Inpatient.h"
#include "Outpatient.h"
#include "TriageHelper.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;

// ============================================================
//  HOSPITAL SYSTEM IMPLEMENTATION
//  Contributed by: Shahesh (Mentor)
//  File Persistence, Menu Integration, Main Logic
// ============================================================

HospitalSystem::HospitalSystem() : nextPatientId(1), nextDoctorId(1), nextAppointmentId(1) {
    loadData();
    if (doctors.empty()) {
        doctors.push_back(Doctor(nextDoctorId++, "Smith",    "Cardiology"));
        doctors.push_back(Doctor(nextDoctorId++, "Johnson",  "Neurology"));
        doctors.push_back(Doctor(nextDoctorId++, "Williams", "Pediatrics"));
        doctors.push_back(Doctor(nextDoctorId++, "Patel",    "Orthopedics"));
        doctors.push_back(Doctor(nextDoctorId++, "Reddy",    "General Medicine"));
        saveData();
    }
}

HospitalSystem::~HospitalSystem() {
    saveData();
    for (int i = 0; i < (int)patients.size(); i++)
        delete patients[i];
}

void HospitalSystem::saveData() {
    ofstream pf("patients.txt");
    pf << patients.size() << "\n";
    for (int i = 0; i < (int)patients.size(); i++) {
        pf << patients[i]->getPatientType() << "\n";
        patients[i]->save(pf);
    }
    pf.close();

    ofstream df("doctors.txt");
    df << doctors.size() << "\n";
    for (int i = 0; i < (int)doctors.size(); i++)
        doctors[i].save(df);
    df.close();

    ofstream af("appointments.txt");
    af << appointments.size() << "\n";
    for (int i = 0; i < (int)appointments.size(); i++)
        appointments[i].save(af);
    af.close();
}

void HospitalSystem::loadData() {
    ifstream pf("patients.txt");
    if (pf.is_open()) {
        int count = 0;
        pf >> count; pf.ignore();
        for (int i = 0; i < count; i++) {
            string type;
            getline(pf, type);
            Patient* p = NULL;
            if (type == "Inpatient") p = new Inpatient();
            else p = new Outpatient();
            p->load(pf);
            patients.push_back(p);
            if (p->getId() >= nextPatientId)
                nextPatientId = p->getId() + 1;
        }
        pf.close();
    }

    ifstream df("doctors.txt");
    if (df.is_open()) {
        int count = 0;
        df >> count; df.ignore();
        for (int i = 0; i < count; i++) {
            Doctor d;
            d.load(df);
            doctors.push_back(d);
            if (d.getId() >= nextDoctorId)
                nextDoctorId = d.getId() + 1;
        }
        df.close();
    }

    ifstream af("appointments.txt");
    if (af.is_open()) {
        int count = 0;
        af >> count; af.ignore();
        for (int i = 0; i < count; i++) {
            Appointment a;
            a.load(af);
            appointments.push_back(a);
            if (a.getAppointmentId() >= nextAppointmentId)
                nextAppointmentId = a.getAppointmentId() + 1;
        }
        af.close();
    }
}

Patient* HospitalSystem::findPatient(int id) {
    for (int i = 0; i < (int)patients.size(); i++)
        if (patients[i]->getId() == id) return patients[i];
    return NULL;
}

Doctor* HospitalSystem::findDoctor(int id) {
    for (int i = 0; i < (int)doctors.size(); i++)
        if (doctors[i].getId() == id) return &doctors[i];
    return NULL;
}

void HospitalSystem::admitPatient() {
    cout << "\n--- ADMIT NEW PATIENT ---\n";
    cout << "1. Inpatient (needs bed)\n";
    cout << "2. Outpatient (consultation only)\n";
    cout << "Choice: ";
    int type; cin >> type; cin.ignore();

    string name, gender, date;
    int age;

    cout << "Name           : "; getline(cin, name);
    cout << "Age            : "; cin >> age; cin.ignore();
    cout << "Gender (M/F)   : "; getline(cin, gender);
    cout << "Date (DD/MM/YYYY): "; getline(cin, date);

    Patient* p = NULL;

    if (type == 1) {
        int ward, bed;
        cout << "Ward Number    : "; cin >> ward;
        cout << "Bed Number     : "; cin >> bed; cin.ignore();
        p = new Inpatient(nextPatientId++, name, age, gender, date, ward, bed);
    } else {
        string nextApp;
        cout << "Next Appointment (DD/MM/YYYY): "; getline(cin, nextApp);
        p = new Outpatient(nextPatientId++, name, age, gender, date, nextApp);
    }

    cout << "\nAvailable Doctors:\n";
    for (int i = 0; i < (int)doctors.size(); i++) doctors[i].display();
    cout << "Assign Doctor ID: ";
    int docId; cin >> docId; cin.ignore();
    if (findDoctor(docId)) p->assignDoctor(docId);
    else cout << "(Doctor ID not found, skipping assignment)\n";

    patients.push_back(p);
    saveData();
    cout << "\n  Patient admitted! ID: " << p->getId() << "\n";
}

void HospitalSystem::dischargePatient() {
    cout << "\n--- DISCHARGE PATIENT ---\n";
    cout << "Enter Patient ID: ";
    int id; cin >> id; cin.ignore();

    Patient* p = findPatient(id);
    if (p == NULL || !p->isAdmitted()) {
        cout << "  Patient not found or already discharged.\n";
        return;
    }

    cout << "\n--- DISCHARGE SUMMARY ---\n";
    p->printRecord();
    cout << "  Total Bill: Rs." << p->calculateBill() << "\n";
    p->discharge();
    saveData();
    cout << "\n  Patient discharged successfully.\n";
}

void HospitalSystem::viewAllPatients() {
    if (patients.empty()) { cout << "\n  No patients in system.\n"; return; }
    sort(patients.begin(), patients.end(),
         [](Patient* a, Patient* b) { return *a < *b; });
    cout << "\n--- ALL PATIENTS (" << patients.size() << ") ---\n";
    for (int i = 0; i < (int)patients.size(); i++)
        patients[i]->printRecord();
}

void HospitalSystem::searchPatient() {
    cout << "\n--- SEARCH PATIENT ---\n";
    cout << "1. By ID\n2. By Name\nChoice: ";
    int ch; cin >> ch; cin.ignore();
    if (ch == 1) {
        cout << "Patient ID: ";
        int id; cin >> id; cin.ignore();
        Patient* p = findPatient(id);
        if (p) p->printRecord();
        else cout << "  Not found.\n";
    } else {
        cout << "Name (partial OK): ";
        string name; getline(cin, name);
        bool found = false;
        for (int i = 0; i < (int)patients.size(); i++) {
            if (patients[i]->getName().find(name) != string::npos) {
                patients[i]->printRecord();
                found = true;
            }
        }
        if (!found) cout << "  No matching patient found.\n";
    }
}

void HospitalSystem::wardCensus() {
    cout << "\n--- WARD-WISE PATIENT CENSUS ---\n";
    bool any = false;
    for (int i = 0; i < (int)patients.size(); i++) {
        if (patients[i]->isAdmitted() && patients[i]->getPatientType() == "Inpatient") {
            patients[i]->printRecord();
            any = true;
        }
    }
    if (!any) cout << "  No inpatients currently admitted.\n";
}

void HospitalSystem::bookAppointment() {
    cout << "\n--- BOOK APPOINTMENT ---\n";
    int pid, did;
    string date, time;
    cout << "Patient ID : "; cin >> pid; cin.ignore();
    if (!findPatient(pid)) { cout << "  Patient not found.\n"; return; }
    cout << "\nAvailable Doctors:\n";
    for (int i = 0; i < (int)doctors.size(); i++) doctors[i].display();
    cout << "Doctor ID  : "; cin >> did; cin.ignore();
    cout << "Date (DD/MM/YYYY): "; getline(cin, date);
    cout << "Time (HH:MM)     : "; getline(cin, time);
    appointments.push_back(Appointment(nextAppointmentId++, pid, did, date, time));
    saveData();
    cout << "  Appointment booked. ID: " << nextAppointmentId - 1 << "\n";
}

void HospitalSystem::cancelAppointment() {
    cout << "\n--- CANCEL APPOINTMENT ---\n";
    cout << "Enter Appointment ID: ";
    int id; cin >> id; cin.ignore();
    for (int i = 0; i < (int)appointments.size(); i++) {
        if (appointments[i].getAppointmentId() == id) {
            appointments[i].cancel();
            saveData();
            cout << "  Appointment cancelled.\n";
            return;
        }
    }
    cout << "  Appointment not found.\n";
}

void HospitalSystem::viewAppointments() {
    cout << "\n--- APPOINTMENTS ---\n";
    if (appointments.empty()) { cout << "  No appointments.\n"; return; }
    for (int i = 0; i < (int)appointments.size(); i++)
        appointments[i].display();
}

void HospitalSystem::viewBill() {
    cout << "\n--- VIEW BILL ---\n";
    cout << "Patient ID: ";
    int id; cin >> id; cin.ignore();
    Patient* p = findPatient(id);
    if (!p) { cout << "  Patient not found.\n"; return; }
    cout << "  Patient : " << p->getName() << "\n";
    cout << "  Type    : " << p->getPatientType() << "\n";
    cout << "  Total Bill: Rs." << p->calculateBill() << "\n";
}

void HospitalSystem::triageHelper() {
    TriageHelper t;
    t.assess();
}

void HospitalSystem::mainMenu() {
    int choice;
    do {
        cout << "\n";
        cout << "+--------------------------------------------+\n";
        cout << "|     HOSPITAL PATIENT RECORD SYSTEM         |\n";
        cout << "+--------------------------------------------+\n";
        cout << "|  1.  Admit New Patient                     |\n";
        cout << "|  2.  Discharge Patient                     |\n";
        cout << "|  3.  View All Patients                     |\n";
        cout << "|  4.  Search Patient                        |\n";
        cout << "|  5.  Ward Census (Inpatients)              |\n";
        cout << "|  6.  Book Appointment                      |\n";
        cout << "|  7.  Cancel Appointment                    |\n";
        cout << "|  8.  View All Appointments                 |\n";
        cout << "|  9.  View Patient Bill                     |\n";
        cout << "|  10. Triage Helper                         |\n";
        cout << "|  0.  Exit                                  |\n";
        cout << "+--------------------------------------------+\n";
        cout << "Choice: ";
        cin >> choice; cin.ignore();
        switch (choice) {
            case 1:  admitPatient();      break;
            case 2:  dischargePatient();  break;
            case 3:  viewAllPatients();   break;
            case 4:  searchPatient();     break;
            case 5:  wardCensus();        break;
            case 6:  bookAppointment();   break;
            case 7:  cancelAppointment(); break;
            case 8:  viewAppointments();  break;
            case 9:  viewBill();          break;
            case 10: triageHelper();      break;
            case 0:  cout << "\n  Goodbye!\n"; break;
            default: cout << "\n  Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}
