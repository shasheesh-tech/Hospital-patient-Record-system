#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// ============================================================
//  DOCTOR CLASS
//  Purpose: Stores doctor information
//  Contributed by: Rithvik
// ============================================================

class Doctor {
private:
    int    id;              // Doctor's unique ID
    string name;            // Doctor's full name
    string specialization;  // Doctor's specialty (Cardiology, Neurology, etc.)

public:
    // ============================================================
    //  CONSTRUCTORS
    //  Purpose: Create doctor objects
    // ============================================================
    
    // Default constructor - creates empty doctor
    Doctor();
    
    // Parameterized constructor - creates doctor with all details
    Doctor(int docId, string docName, string docSpecialization);

    // ============================================================
    //  GETTER FUNCTIONS
    //  Purpose: Access private data safely
    // ============================================================
    
    // Returns doctor's ID
    int getId() const;
    
    // Returns doctor's name
    string getName() const;
    
    // Returns doctor's specialization
    string getSpec() const;

    // ============================================================
    //  DISPLAY FUNCTION
    //  Purpose: Show doctor details on screen
    // ============================================================
    void display() const;

    // ============================================================
    //  FILE HANDLING FUNCTIONS
    //  Purpose: Save and load doctor data
    // ============================================================
    
    // Writes doctor data to file
    void save(ofstream& outFile) const;
    
    // Reads doctor data from file
    void load(ifstream& inFile);
};

#endif
