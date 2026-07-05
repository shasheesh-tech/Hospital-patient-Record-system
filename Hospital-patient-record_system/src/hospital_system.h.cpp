#ifndef HOSPITALSYSTEM_H
#define HOSPITALSYSTEM_H

#include <vector>
#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"

// ============================================================
//  MAIN HOSPITAL SYSTEM CLASS
//  Contributed by: Shahesh (Mentor)
//  Role: System Integration, File I/O, Main Menu
// ============================================================

class HospitalSystem {
private:
    vector<Patient*>    patients;
    vector<Doctor>      doctors;
    vector<Appointment> appointments;
    int nextPatientId;
    int nextDoctorId;
    int nextAppointmentId;

    void saveData();
    void loadData();
    Patient* findPatient(int id);
    Doctor* findDoctor(int id);

public:
    HospitalSystem();
    ~HospitalSystem();
    
    void admitPatient();
    void dischargePatient();
    void viewAllPatients();
    void searchPatient();
    void wardCensus();
    void bookAppointment();
    void cancelAppointment();
    void viewAppointments();
    void viewBill();
    void triageHelper();
    void mainMenu();
};

#endif
