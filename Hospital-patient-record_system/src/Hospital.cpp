#include "../include/Hospital.h"
#include "../include/Inpatient.h"
#include "../include/Outpatient.h"
#include "../include/TriageHelper.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

// ============================================================
//  HOSPITAL SYSTEM IMPLEMENTATION
//  Contributed by: Shahesh (Mentor)
// ============================================================

// ============================================================
//  CONSTRUCTOR & DESTRUCTOR
// ============================================================

// Constructor
// Loads existing data and adds default doctors if needed
HospitalSystem::HospitalSystem() {
    nextPatientId = 1;
    nextDoctorId = 1;
    nextAppointmentId = 1;
    
    // Load data from files
    loadData();
    
    // Check if doctors exist
    if (doctors.empty()) {
        // Add default doctors
        Doctor doc1(nextDoctorId++, "Smith", "Cardiology");
        doctors.push_back(doc1);
        
        Doctor doc2(nextDoctorId++, "Johnson", "Neurology");
        doctors.push_back(doc2);
        
        Doctor doc3(nextDoctorId++, "Williams", "Pediatrics");
        doctors.push_back(doc3);
        
        Doctor doc4(nextDoctorId++, "Patel", "Orthopedics");
        doctors.push_back(doc4);
        
        Doctor doc5(nextDoctorId++, "Reddy", "General Medicine");
        doctors.push_back(doc5);
        
        // Save default doctors to file
        saveData();
    }
}

// Destructor
// Saves data and deletes patient objects
HospitalSystem::~HospitalSystem() {
    // Save all data
    saveData();
    
    // Delete patient objects
    for (int i = 0; i < (int)patients.size(); i++) {
        delete patients[i];
    }
}

// ============================================================
//  PRIVATE HELPER FUNCTIONS
// ============================================================

// ============================================================
//  SAVE DATA FUNCTION
//  Purpose: Save all data to text files
// ============================================================

void HospitalSystem::saveData() {
    // --- Save patients ---
    ofstream patientFile("patients.txt");
    
    patientFile << patients.size() << "\n";
    
    for (int i = 0; i < (int)patients.size(); i++) {
        string patientType = patients[i]->getPatientType();
        patientFile << patientType << "\n";
        patients[i]->save(patientFile);
    }
    
    patientFile.close();
    
    // --- Save doctors ---
    ofstream doctorFile("doctors.txt");
    
    doctorFile << doctors.size() << "\n";
    
    for (int i = 0; i < (int)doctors.size(); i++) {
        doctors[i].save(doctorFile);
    }
    
    doctorFile.close();
    
    // --- Save appointments ---
    ofstream appointmentFile("appointments.txt");
    
    appointmentFile << appointments.size() << "\n";
    
    for (int i = 0; i < (int)appointments.size(); i++) {
        appointments[i].save(appointmentFile);
    }
    
    appointmentFile.close();
}

// ============================================================
//  LOAD DATA FUNCTION
//  Purpose: Load all data from text files
// ============================================================

void HospitalSystem::loadData() {
    // --- Load patients ---
    ifstream patientFile("patients.txt");
    
    if (patientFile.is_open()) {
        int count = 0;
        patientFile >> count;
        patientFile.ignore();  // Skip newline
        
        for (int i = 0; i < count; i++) {
            string type;
            getline(patientFile, type);
            
            Patient* p = NULL;
            
            if (type == "Inpatient") {
                p = new Inpatient();
            } else {
                p = new Outpatient();
            }
            
            p->load(patientFile);
            patients.push_back(p);
            
            // Update next available ID
            if (p->getId() >= nextPatientId) {
                nextPatientId = p->getId() + 1;
            }
        }
        
        patientFile.close();
    }
    
    // --- Load doctors ---
    ifstream doctorFile("doctors.txt");
    
    if (doctorFile.is_open()) {
        int count = 0;
        doctorFile >> count;
        doctorFile.ignore();  // Skip newline
        
        for (int i = 0; i < count; i++) {
            Doctor d;
            d.load(doctorFile);
            doctors.push_back(d);
            
            // Update next available ID
            if (d.getId() >= nextDoctorId) {
                nextDoctorId = d.getId() + 1;
            }
        }
        
        doctorFile.close();
    }
    
    // --- Load appointments ---
    ifstream appointmentFile
