#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// ============================================================
//  APPOINTMENT CLASS
//  Purpose: Manages patient appointments with doctors
//  Contributed by: Rithvik
// ============================================================

class Appointment {
private:
    int    appointmentId;  // Unique appointment ID
    int    patientId;      // ID of patient who booked appointment
    int    doctorId;       // ID of doctor for the appointment
    string date;           // Appointment date (DD/MM/YYYY)
    string time;           // Appointment time (HH:MM)
    bool   booked;         // True if appointment is active

public:
    // ============================================================
    //  CONSTRUCTORS
    //  Purpose: Create appointment objects
    // ============================================================
    
    // Default constructor
    Appointment();
    
    // Parameterized constructor
    Appointment(int appointmentId, int patientId, int doctorId,
                string date, string time);

    // ============================================================
    //  SETTER & GETTER FUNCTIONS
    // ============================================================
    
    // Cancels the appointment
    void cancel();
    
    // Returns appointment ID
    int getAppointmentId() const;
    
    // Returns patient ID
    int getPatientId() const;
    
    // Returns doctor ID
    int getDoctorId() const;
    
    // Returns booking status
    bool isBooked() const;

    // ============================================================
    //  DISPLAY FUNCTION
    //  Purpose: Show appointment details
    // ============================================================
    void display() const;

    // ============================================================
    //  FILE HANDLING
    //  Purpose: Save and load appointment data
    // ============================================================
    void save(ofstream& outFile) const;
    void load(ifstream& inFile);
};

#endif
