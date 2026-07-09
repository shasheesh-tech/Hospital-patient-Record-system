#include "../include/Doctor.h"

// ============================================================
//  DOCTOR CLASS IMPLEMENTATION
//  Contributed by: Rithvik
// ============================================================

// ============================================================
//  CONSTRUCTORS
//  Purpose: Create doctor objects
// ============================================================

// Default constructor
// Sets all values to default (empty)
Doctor::Doctor() {
    id = 0;
    name = "";
    specialization = "";
}

// Parameterized constructor
// Sets values based on parameters passed
Doctor::Doctor(int docId, string docName, string docSpecialization) {
    id = docId;
    name = docName;
    specialization = docSpecialization;
}

// ============================================================
//  GETTER FUNCTIONS
//  Purpose: Return private data to outside
// ============================================================

// Returns doctor's ID
int Doctor::getId() const {
    return id;
}

// Returns doctor's name
string Doctor::getName() const {
    return name;
}

// Returns doctor's specialization
string Doctor::getSpec() const {
    return specialization;
}

// ============================================================
//  DISPLAY FUNCTION
//  Purpose: Print doctor details on console
// ============================================================

void Doctor::display() const {
    cout << "  [" << id << "] Dr. " << name;
    cout << " - " << specialization;
    cout << "\n";
}

// ============================================================
//  FILE HANDLING FUNCTIONS
//  Purpose: Save and load doctor data
// ============================================================

// Writes doctor data to file
void Doctor::save(ofstream& outFile) const {
    outFile << id << "\n";
    outFile << name << "\n";
    outFile << specialization << "\n";
}

// Reads doctor data from file
void Doctor::load(ifstream& inFile) {
    inFile >> id;
    inFile.ignore();  // Skip newline character
    
    getline(inFile, name);
    getline(inFile, specialization);
}
