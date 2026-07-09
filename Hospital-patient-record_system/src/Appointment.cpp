#include "../include/Appointment.h"

// ============================================================
//  APPOINTMENT CLASS IMPLEMENTATION
//  Contributed by: Rithvik
// ============================================================

// ============================================================
//  CONSTRUCTORS
// ============================================================

// Default constructor
Appointment::Appointment() {
    appointmentId = 0;
    patientId = 0;
    doctorId = 0;
    date = "";
    time = "";
    booked = false;
}

// Parameterized constructor
Appointment::Appointment(int id, int pId, int dId, string appDate, string appTime) {
    appointmentId = id;
    patientId = pId;
    doctorId = dId;
    date = appDate;
    time = appTime;
    booked = true;  // New appointment is booked by default
}

// ============================================================
//  SETTER & GETTER FUNCTIONS
// ============================================================

// Cancels appointment by setting booked to false
void Appointment::cancel() {
    booked = false;
}

int Appointment::getAppointmentId() const {
    return appointmentId;
}

int Appointment::getPatientId() const {
    return patientId;
}

int Appointment::getDoctorId() const {
    return doctorId;
}

bool Appointment::isBooked() const {
    return booked;
}

// ============================================================
//  DISPLAY FUNCTION
//  Purpose: Print appointment details on console
// ============================================================

void Appointment::display() const {
    cout << "  Appointment #" << appointmentId;
    cout << " | Patient ID: " << patientId;
    cout << " | Doctor ID: " << doctorId;
    cout << " | Date: " << date;
    cout << " | Time: " << time;
    
    if (!booked) {
        cout << "  [CANCELLED]";
    }
    
    cout << "\n";
}

// ============================================================
//  FILE HANDLING
// ============================================================

void Appointment::save(ofstream& outFile) const {
    outFile << appointmentId << "\n";
    outFile << patientId << "\n";
    outFile << doctorId << "\n";
    outFile << date << "\n";
    outFile << time << "\n";
    outFile << booked << "\n";
}

void Appointment::load(ifstream& inFile) {
    inFile >> appointmentId;
    inFile >> patientId;
    inFile >> doctorId;
    inFile.ignore();  // Skip newline
    
    getline(inFile, date);
    getline(inFile, time);
    
    inFile >> booked;
    inFile.ignore();  // Skip newline
}
