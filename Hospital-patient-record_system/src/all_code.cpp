#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

// ============================================================
//  HOSPITAL PATIENT RECORD SYSTEM
//  OOP Concepts Used:
//  - Encapsulation  : private data, public methods
//  - Inheritance    : Inpatient / Outpatient extend Patient
//  - Polymorphism   : virtual printRecord() and calculateBill()
//  - Operator Overload : < and > on Patient
//  - File Streams   : fstream for save/load
//  - STL Vector     : stores all patients, doctors, appointments
// ============================================================

// ============================================================
//  DOCTOR CLASS
// ============================================================
class Doctor {
private:
    int    id;
    string name;
    string specialization;

public:
    Doctor() : id(0), name(""), specialization("") {}

    Doctor(int i, string n, string s)
        : id(i), name(n), specialization(s) {}

    int    getId()   const { return id; }
    string getName() const { return name; }
    string getSpec() const { return specialization; }

    void display() const {
        cout << "  [" << id << "] Dr. " << name
             << " - " << specialization << "\n";
    }

    void save(ofstream& out) const {
        out << id << "\n" << name << "\n" << specialization << "\n";
    }

    void load(ifstream& in) {
        in >> id;
        in.ignore();
        getline(in, name);
        getline(in, specialization);
    }
};

// ============================================================
//  ABSTRACT BASE CLASS: Patient
//  Encapsulation: all data private, accessed via methods
// ============================================================
class Patient {
protected:
    int    id;
    string name;
    int    age;
    string gender;
    string admissionDate;
    bool   admitted;
    int    assignedDoctorId;

public:
    Patient() : id(0), name(""), age(0), gender(""),
                admissionDate(""), admitted(false), assignedDoctorId(-1) {}

    Patient(int i, string n, int a, string g, string date)
        : id(i), name(n), age(a), gender(g),
          admissionDate(date), admitted(true), assignedDoctorId(-1) {}

    virtual ~Patient() {}

    // Pure virtual functions -- Polymorphism
    virtual double calculateBill()    const = 0;
    virtual void   printRecord()      const = 0;
    virtual string getPatientType()   const = 0;

    // Operator overloading
    bool operator<(const Patient& o) const { return id < o.id; }
    bool operator>(const Patient& o) const { return id > o.id; }

    // Getters
    int    getId()            const { return id; }
    string getName()          const { return name; }
    int    getAge()           const { return age; }
    bool   isAdmitted()       const { return admitted; }
    int    getDoctorId()      const { return assignedDoctorId; }

    // Setters
    void assignDoctor(int docId) { assignedDoctorId = docId; }
    void discharge()             { admitted = false; }

    // File helpers (shared base fields)
    virtual void save(ofstream& out) const {
        out << id << "\n" << name << "\n" << age << "\n"
            << gender << "\n" << admissionDate << "\n"
            << admitted << "\n" << assignedDoctorId << "\n";
    }

    virtual void load(ifstream& in) {
        in >> id;
        in.ignore();
        getline(in, name);
        in >> age;
        in.ignore();
        getline(in, gender);
        getline(in, admissionDate);
        in >> admitted >> assignedDoctorId;
        in.ignore();
    }
};

// ============================================================
//  DERIVED CLASS: Inpatient  (Inheritance)
// ============================================================
class Inpatient : public Patient {
private:
    int wardNumber;
    int bedNumber;
    int daysAdmitted;

public:
    Inpatient() : Patient(), wardNumber(0), bedNumber(0), daysAdmitted(0) {}

    Inpatient(int i, string n, int a, string g, string date, int ward, int bed)
        : Patient(i, n, a, g, date), wardNumber(ward), bedNumber(bed), daysAdmitted(1) {}

    void setDays(int d) { daysAdmitted = d; }
    int  getWard()      const { return wardNumber; }
    int  getBed()       const { return bedNumber; }
    int  getDays()      const { return daysAdmitted; }

    // Polymorphism: Inpatient bill = room + doctor fee per day
    double calculateBill() const override {
        double roomCharge = 2000.0 * daysAdmitted;
        double doctorFee  =  500.0 * daysAdmitted;
        return roomCharge + doctorFee;
    }

    string getPatientType() const override { return "Inpatient"; }

    void printRecord() const override {
        cout << "+--------------------------------------------+\n";
        cout << "|          INPATIENT RECORD                  |\n";
        cout << "+--------------------------------------------+\n";
        cout << "| ID      : " << left << setw(33) << id          << "|\n";
        cout << "| Name    : " << left << setw(33) << name        << "|\n";
        cout << "| Age     : " << left << setw(33) << age         << "|\n";
        cout << "| Gender  : " << left << setw(33) << gender      << "|\n";
        cout << "| Admitted: " << left << setw(33) << admissionDate << "|\n";
        cout << "| Ward    : " << left << setw(33) << wardNumber  << "|\n";
        cout << "| Bed     : " << left << setw(33) << bedNumber   << "|\n";
        cout << "| Days    : " << left << setw(33) << daysAdmitted << "|\n";
        cout << "| Bill    : Rs." << left << setw(30) << calculateBill() << "|\n";
        cout << "+--------------------------------------------+\n";
    }

    void save(ofstream& out) const override {
        Patient::save(out);
        out << wardNumber << "\n" << bedNumber << "\n" << daysAdmitted << "\n";
    }

    void load(ifstream& in) override {
        Patient::load(in);
        in >> wardNumber >> bedNumber >> daysAdmitted;
        in.ignore();
    }
};

// ============================================================
//  DERIVED CLASS: Outpatient  (Inheritance)
// ============================================================
class Outpatient : public Patient {
private:
    string nextAppointment;

public:
    Outpatient() : Patient(), nextAppointment("") {}

    Outpatient(int i, string n, int a, string g, string date, string nextApp)
        : Patient(i, n, a, g, date), nextAppointment(nextApp) {}

    string getNextAppointment() const { return nextAppointment; }

    // Polymorphism: Outpatient bill = flat consultation fee
    double calculateBill() const override { return 500.0; }

    string getPatientType() const override { return "Outpatient"; }

    void printRecord() const override {
        cout << "+--------------------------------------------+\n";
        cout << "|          OUTPATIENT RECORD                 |\n";
        cout << "+--------------------------------------------+\n";
        cout << "| ID         : " << left << setw(30) << id              << "|\n";
        cout << "| Name       : " << left << setw(30) << name            << "|\n";
        cout << "| Age        : " << left << setw(30) << age             << "|\n";
        cout << "| Gender     : " << left << setw(30) << gender          << "|\n";
        cout << "| Visit Date : " << left << setw(30) << admissionDate   << "|\n";
        cout << "| Next Appt  : " << left << setw(30) << nextAppointment << "|\n";
        cout << "| Bill       : Rs." << left << setw(27) << calculateBill() << "|\n";
        cout << "+--------------------------------------------+\n";
    }

    void save(ofstream& out) const override {
        Patient::save(out);
        out << nextAppointment << "\n";
    }

    void load(ifstream& in) override {
        Patient::load(in);
        getline(in, nextAppointment);
    }
};

// ============================================================
//  APPOINTMENT CLASS
// ============================================================
class Appointment {
private:
    int    appointmentId;
    int    patientId;
    int    doctorId;
    string date;
    string time;
    bool   booked;

public:
    Appointment() : appointmentId(0), patientId(0), doctorId(0),
                    date(""), time(""), booked(false) {}

    Appointment(int aid, int pid, int did, string d, string t)
        : appointmentId(aid), patientId(pid), doctorId(did),
          date(d), time(t), booked(true) {}

    void cancel()            { booked = false; }
    int  getAppointmentId()  const { return appointmentId; }
    int  getPatientId()      const { return patientId; }
    int  getDoctorId()       const { return doctorId; }
    bool isBooked()          const { return booked; }

    void display() const {
        cout << "  Appointment #" << appointmentId
             << " | Patient ID: " << patientId
             << " | Doctor ID: "  << doctorId
             << " | Date: " << date
             << " | Time: " << time;
        if (!booked) cout << "  [CANCELLED]";
        cout << "\n";
    }

    void save(ofstream& out) const {
        out << appointmentId << "\n" << patientId << "\n" << doctorId << "\n"
            << date << "\n" << time << "\n" << booked << "\n";
    }

    void load(ifstream& in) {
        in >> appointmentId >> patientId >> doctorId;
        in.ignore();
        getline(in, date);
        getline(in, time);
        in >> booked;
        in.ignore();
    }
};

// ============================================================
//  RULE-BASED TRIAGE HELPER
// ============================================================
class TriageHelper {
private:
    struct Rule {
        string keyword;
        string department;
        string urgency;
    };
    vector<Rule> rules;

public:
    TriageHelper() {
        rules.push_back({"chest pain",   "Cardiology",       "EMERGENCY"});
        rules.push_back({"heart",        "Cardiology",       "EMERGENCY"});
        rules.push_back({"breathless",   "Pulmonology",      "URGENT"});
        rules.push_back({"cough",        "Pulmonology",      "NORMAL"});
        rules.push_back({"fever",        "General Medicine", "NORMAL"});
        rules.push_back({"headache",     "Neurology",        "NORMAL"});
        rules.push_back({"fracture",     "Orthopedics",      "URGENT"});
        rules.push_back({"burn",         "Plastic Surgery",  "EMERGENCY"});
        rules.push_back({"stomach",      "Gastroenterology", "NORMAL"});
        rules.push_back({"eye",          "Ophthalmology",    "NORMAL"});
        rules.push_back({"child",        "Pediatrics",       "URGENT"});
        rules.push_back({"pregnant",     "Obstetrics",       "URGENT"});
    }

    void assess() {
        cout << "\n--- TRIAGE HELPER ---\n";
        cout << "Describe patient symptoms: ";
        string input;
        getline(cin, input);

        // Convert to lowercase for matching
        string lower = input;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

        bool found = false;
        for (int i = 0; i < (int)rules.size(); i++) {
            if (lower.find(rules[i].keyword) != string::npos) {
                cout << "\n  Recommended Department : " << rules[i].department << "\n";
                cout << "  Urgency Level         : " << rules[i].urgency << "\n";
                if (rules[i].urgency == "EMERGENCY")
                    cout << "  *** SEND TO EMERGENCY ROOM IMMEDIATELY ***\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\n  Recommended Department : General Medicine\n";
            cout << "  Urgency Level         : NORMAL\n";
        }
    }
};

// ============================================================
//  MAIN HOSPITAL SYSTEM CLASS
// ============================================================
class HospitalSystem {
private:
    vector<Patient*>    patients;
    vector<Doctor>      doctors;
    vector<Appointment> appointments;
    int nextPatientId;
    int nextDoctorId;
    int nextAppointmentId;

    // -- File I/O ------------------------------------------
    void saveData() {
        // Save patients
        ofstream pf("patients.txt");
        pf << patients.size() << "\n";
        for (int i = 0; i < (int)patients.size(); i++) {
            pf << patients[i]->getPatientType() << "\n";
            patients[i]->save(pf);
        }
        pf.close();

        // Save doctors
        ofstream df("doctors.txt");
        df << doctors.size() << "\n";
        for (int i = 0; i < (int)doctors.size(); i++)
            doctors[i].save(df);
        df.close();

        // Save appointments
        ofstream af("appointments.txt");
        af << appointments.size() << "\n";
        for (int i = 0; i < (int)appointments.size(); i++)
            appointments[i].save(af);
        af.close();
    }

    void loadData() {
        // Load patients
        ifstream pf("patients.txt");
        if (pf.is_open()) {
            int count = 0;
            pf >> count;
            pf.ignore();
            for (int i = 0; i < count; i++) {
                string type;
                getline(pf, type);
                Patient* p = NULL;
                if (type == "Inpatient")  p = new Inpatient();
                else                      p = new Outpatient();
                p->load(pf);
                patients.push_back(p);
                if (p->getId() >= nextPatientId)
                    nextPatientId = p->getId() + 1;
            }
            pf.close();
        }

        // Load doctors
        ifstream df("doctors.txt");
        if (df.is_open()) {
            int count = 0;
            df >> count;
            df.ignore();
            for (int i = 0; i < count; i++) {
                Doctor d;
                d.load(df);
                doctors.push_back(d);
                if (d.getId() >= nextDoctorId)
                    nextDoctorId = d.getId() + 1;
            }
            df.close();
        }

        // Load appointments
        ifstream af("appointments.txt");
        if (af.is_open()) {
            int count = 0;
            af >> count;
            af.ignore();
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

    // -- Helper: find patient by ID ------------------------
    Patient* findPatient(int id) {
        for (int i = 0; i < (int)patients.size(); i++)
            if (patients[i]->getId() == id) return patients[i];
        return NULL;
    }

    Doctor* findDoctor(int id) {
        for (int i = 0; i < (int)doctors.size(); i++)
            if (doctors[i].getId() == id) return &doctors[i];
        return NULL;
    }

public:
    HospitalSystem() : nextPatientId(1), nextDoctorId(1), nextAppointmentId(1) {
        loadData();
        // Add default doctors if none loaded
        if (doctors.empty()) {
            doctors.push_back(Doctor(nextDoctorId++, "Smith",    "Cardiology"));
            doctors.push_back(Doctor(nextDoctorId++, "Johnson",  "Neurology"));
            doctors.push_back(Doctor(nextDoctorId++, "Williams", "Pediatrics"));
            doctors.push_back(Doctor(nextDoctorId++, "Patel",    "Orthopedics"));
            doctors.push_back(Doctor(nextDoctorId++, "Reddy",    "General Medicine"));
            saveData();
        }
    }

    ~HospitalSystem() {
        saveData();
        for (int i = 0; i < (int)patients.size(); i++)
            delete patients[i];
    }

    // -- 1. Admit Patient ----------------------------------
    void admitPatient() {
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

        // Assign doctor
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

    // -- 2. Discharge Patient ------------------------------
    void dischargePatient() {
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

    // -- 3. View All Patients ------------------------------
    void viewAllPatients() {
        if (patients.empty()) { cout << "\n  No patients in system.\n"; return; }

        // Sort by ID using operator< (operator overloading demo)
        sort(patients.begin(), patients.end(),
             [](Patient* a, Patient* b) { return *a < *b; });

        cout << "\n--- ALL PATIENTS (" << patients.size() << ") ---\n";
        for (int i = 0; i < (int)patients.size(); i++)
            patients[i]->printRecord();   // Polymorphism: correct version called
    }

    // -- 4. Search Patient ---------------------------------
    void searchPatient() {
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

    // -- 5. Ward Census ------------------------------------
    void wardCensus() {
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

    // -- 6. Book Appointment -------------------------------
    void bookAppointment() {
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

        appointments.push_back(
            Appointment(nextAppointmentId++, pid, did, date, time));
        saveData();
        cout << "  Appointment booked. ID: " << nextAppointmentId - 1 << "\n";
    }

    // -- 7. Cancel Appointment -----------------------------
    void cancelAppointment() {
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

    // -- 8. View Appointments ------------------------------
    void viewAppointments() {
        cout << "\n--- APPOINTMENTS ---\n";
        if (appointments.empty()) { cout << "  No appointments.\n"; return; }
        for (int i = 0; i < (int)appointments.size(); i++)
            appointments[i].display();
    }

    // -- 9. Bill a Patient ---------------------------------
    void viewBill() {
        cout << "\n--- VIEW BILL ---\n";
        cout << "Patient ID: ";
        int id; cin >> id; cin.ignore();
        Patient* p = findPatient(id);
        if (!p) { cout << "  Patient not found.\n"; return; }
        cout << "  Patient : " << p->getName() << "\n";
        cout << "  Type    : " << p->getPatientType() << "\n";
        cout << "  Total Bill: Rs." << p->calculateBill() << "\n";
    }

    // -- 10. Triage ----------------------------------------
    void triageHelper() {
        TriageHelper t;
        t.assess();
    }

    // -- Main Menu -----------------------------------------
    void mainMenu() {
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
};

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "\n";
    cout << "+--------------------------------------------------+\n";
    cout << "|     HOSPITAL PATIENT RECORD SYSTEM               |\n";
    cout << "|     OOP-based Console Application  v1.0          |\n";
    cout << "+--------------------------------------------------+\n";

    HospitalSystem system;
    system.mainMenu();

    return 0;
}
