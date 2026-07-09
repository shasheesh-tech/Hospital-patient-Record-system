#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <vector>
#include "Patient.h"
#include "Doctor.h"
#include "Appointment.h"

using namespace std;

// ============================================================
//  MAIN HOSPITAL SYSTEM CLASS
//  Purpose: Manages all hospital operations
//  Contributed by: Shahesh (Mentor)
// ============================================================

class HospitalSystem {
private:
    // ============================================================
    //  DATA MEMBERS
    //  Purpose: Store all hospital data
    // ============================================================
    
    vector<Patient*>    patients;        // List of all patients
    vector<Doctor>      doctors;         // List of all doctors
    vector<Appointment> appointments;    // List of all appointments
    int nextPatientId;                   // Next available patient ID
    int nextDoctorId;                    // Next available doctor ID
    int nextAppointmentId;               // Next available appointment ID

    // ============================================================
    //  PRIVATE HELPER FUNCTIONS
    //  Purpose: Internal operations
    // ============================================================
    
    void saveData();        // Save all data to files
    void loadData();        // Load all data from files
    Patient* findPatient(int id);   // Find patient by ID
    Doctor* findDoctor(int id);     // Find doctor by ID

public:
    // ============================================================
    //  CONSTRUCTOR & DESTRUCTOR
    // ============================================================
    HospitalSystem();   // Loads data and sets up system
    ~HospitalSystem();  // Saves data and cleans up memory

    // ============================================================
    //  PATIENT MANAGEMENT FUNCTIONS
    // ============================================================
    void admitPatient();        // Admit new patient
    void dischargePatient();    // Discharge and bill patient
    void viewAllPatients();     // Display all patients
    void searchPatient();       // Search by ID or name
    void wardCensus();          // Show all inpatients
    void viewBill();            // View patient bill

    // ============================================================
    //  APPOINTMENT MANAGEMENT FUNCTIONS
    // ============================================================
    void bookAppointment();     // Book new appointment
    void cancelAppointment();   // Cancel existing appointment
    void viewAppointments();    // View all appointments

    // ============================================================
    //  TRIAGE HELPER
    // ============================================================
    void triageHelper();        // Run symptom checker

    // ============================================================
    //  MAIN MENU
    // ============================================================
    void mainMenu();            // Display and handle menu
};

#endif
