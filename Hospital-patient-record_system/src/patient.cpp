#include "../include/Patient.h"
#include <iomanip>

// ============================================================
//  PATIENT CLASS IMPLEMENTATION
//  Contributed by: Varshitha (Team Lead)
// ============================================================

// ============================================================
//  CONSTRUCTORS & DESTRUCTOR
// ============================================================

// Default constructor
// Initializes all values to default (empty)
Patient::Patient() {
    id = 0;
    name = "";
    age = 0;
    gender = "";
    admissionDate = "";
    admitted = false;
    assignedDoctorId = -1;
}

// Parameterized constructor
// Creates patient with given details and marks as admitted
Patient::Patient(int patientId, string patientName, int patientAge,
                 string patientGender, string date) {
    id = patientId;
    name = patientName;
    age = patientAge;
    gender = patientGender;
    admissionDate = date;
    admitted = true;           // Patient starts as admitted
    assignedDoctorId = -1;      // No doctor assigned yet
}

// Virtual destructor
Patient::~Patient() {
    // Nothing to clean up in base class
}

// ============================================================
//  OPERATOR OVERLOADING
//  Purpose: Compare patients by their IDs
// ============================================================

// Checks if this patient's ID is less than other patient's ID
bool Patient::operator<(const Patient& otherPatient) const {
    return id < otherPatient.id;
}

// Checks if this patient's ID is greater than other patient's ID
bool Patient::operator>(const Patient& otherPatient) const {
    return id > otherPatient.id;
}

// ============================================================
//  GETTER FUNCTIONS
//  Purpose: Return private data to outside
// ============================================================

int Patient::getId() const {
    return id;
}

string Patient::getName() const {
    return name;
}

int Patient::getAge() const {
    return age;
}

string Patient::getGender() const {
    return gender;
}

string Patient::getAdmissionDate() const {
    return admissionDate;
}

bool Patient::isAdmitted() const {
    return admitted;
}

int Patient::getDoctorId() const {
    return assignedDoctorId;
}

// ============================================================
//  SETTER FUNCTIONS
//  Purpose: Modify private data
// ============================================================

// Assigns a doctor to this patient
void Patient::assignDoctor(int docId) {
    assignedDoctorId = docId;
}

// Discharges patient by setting admitted to false
void Patient::discharge() {
    admitted = false;
}

// Updates admission date
void Patient::setAdmissionDate(string date) {
    admissionDate = date;
}

// ============================================================
//  FILE HANDLING FUNCTIONS
//  Purpose: Save and load patient data
// ============================================================

// Writes patient data to file
void Patient::save(ofstream& outFile) const {
    outFile << id << "\n";
    outFile << name << "\n";
    outFile << age << "\n";
    outFile << gender << "\n";
    outFile << admissionDate << "\n";
    outFile << admitted << "\n";
    outFile << assignedDoctorId << "\n";
}

// Reads patient data from file
void Patient::load(ifstream& inFile) {
    inFile >> id;
    inFile.ignore();  // Skip newline
    
    getline(inFile, name);
    
    inFile >> age;
    inFile.ignore();  // Skip newline
    
    getline(inFile, gender);
    getline(inFile, admissionDate);
    
    inFile >> admitted;
    inFile >> assignedDoctorId;
    inFile.ignore();  // Skip newline
}

// ============================================================
//  INPATIENT CLASS IMPLEMENTATION
//  Contributed by: Arun
//  Billing: ₹2000/day room + ₹500/day doctor fee
// ============================================================

// ============================================================
//  CONSTRUCTORS
// ============================================================

// Default constructor
// Calls Patient constructor and sets Inpatient-specific values
Inpatient::Inpatient() : Patient() {
    wardNumber = 0;
    bedNumber = 0;
    daysAdmitted = 0;
}

// Parameterized constructor
// Creates Inpatient with ward and bed information
Inpatient::Inpatient(int patientId, string patientName, int patientAge,
                     string patientGender, string date, int ward, int bed)
    : Patient(patientId, patientName, patientAge, patientGender, date) {
    wardNumber = ward;
    bedNumber = bed;
    daysAdmitted = 1;  // Starts with 1 day
}

// ============================================================
//  SETTER & GETTER FUNCTIONS
// ============================================================

void Inpatient::setDays(int days) {
    daysAdmitted = days;
}

int Inpatient::getWard() const {
    return wardNumber;
}

int Inpatient::getBed() const {
    return bedNumber;
}

int Inpatient::getDays() const {
    return daysAdmitted;
}

// ============================================================
//  OVERRIDDEN VIRTUAL FUNCTIONS
// ============================================================

// Calculates bill for Inpatient
// Room charges: ₹2000 per day
// Doctor fee: ₹500 per day
double Inpatient::calculateBill() const {
    double roomCharge = 2000.0 * daysAdmitted;
    double doctorFee = 500.0 * daysAdmitted;
    double totalBill = roomCharge + doctorFee;
    return totalBill;
}

// Returns patient type as string "Inpatient"
string Inpatient::getPatientType() const {
    return "Inpatient";
}

// Prints Inpatient record in a formatted box
void Inpatient::printRecord() const {
    cout << "+--------------------------------------------+\n";
    cout << "|          INPATIENT RECORD                  |\n";
    cout << "+--------------------------------------------+\n";
    cout << "| ID      : " << left << setw(33) << id << "|\n";
    cout << "| Name    : " << left << setw(33) << name << "|\n";
    cout << "| Age     : " << left << setw(33) << age << "|\n";
    cout << "| Gender  : " << left << setw(33) << gender << "|\n";
    cout << "| Admitted: " << left << setw(33) << admissionDate << "|\n";
    cout << "| Ward    : " << left << setw(33) << wardNumber << "|\n";
    cout << "| Bed     : " << left << setw(33) << bedNumber << "|\n";
    cout << "| Days    : " << left << setw(33) << daysAdmitted << "|\n";
    cout << "| Bill    : Rs." << left << setw(30) << calculateBill() << "|\n";
    cout << "+--------------------------------------------+\n";
}

// ============================================================
//  FILE HANDLING
// ============================================================

// Saves Inpatient data to file
void Inpatient::save(ofstream& outFile) const {
    Patient::save(outFile);
    outFile << wardNumber << "\n";
    outFile << bedNumber << "\n";
    outFile << daysAdmitted << "\n";
}

// Loads Inpatient data from file
void Inpatient::load(ifstream& inFile) {
    Patient::load(inFile);
    inFile >> wardNumber;
    inFile >> bedNumber;
    inFile >> daysAdmitted;
    inFile.ignore();  // Skip newline
}

// ============================================================
//  OUTPATIENT CLASS IMPLEMENTATION
//  Contributed by: Arun
//  Billing: Flat ₹500 consultation fee
// ============================================================

// ============================================================
//  CONSTRUCTORS
// ============================================================

// Default constructor
Outpatient::Outpatient() : Patient() {
    nextAppointment = "";
}

// Parameterized constructor
Outpatient::Outpatient(int patientId, string patientName, int patientAge,
                       string patientGender, string date, string nextApp)
    : Patient(patientId, patientName, patientAge, patientGender, date) {
    nextAppointment = nextApp;
}

// ============================================================
//  GETTER FUNCTIONS
// ============================================================

string Outpatient::getNextAppointment() const {
    return nextAppointment;
}

// ============================================================
//  OVERRIDDEN VIRTUAL FUNCTIONS
// ============================================================

// Calculates bill for Outpatient
// Flat consultation fee: ₹500
double Outpatient::calculateBill() const {
    return 500.0;
}

// Returns patient type as string "Outpatient"
string Outpatient::getPatientType() const {
    return "Outpatient";
}

// Prints Outpatient record in a formatted box
void Outpatient::printRecord() const {
    cout << "+--------------------------------------------+\n";
    cout << "|          OUTPATIENT RECORD                 |\n";
    cout << "+--------------------------------------------+\n";
    cout << "| ID         : " << left << setw(30) << id << "|\n";
    cout << "| Name       : " << left << setw(30) << name << "|\n";
    cout << "| Age        : " << left << setw(30) << age << "|\n";
    cout << "| Gender     : " << left << setw(30) << gender << "|\n";
    cout << "| Visit Date : " << left << setw(30) << admissionDate << "|\n";
    cout << "| Next Appt  : " << left << setw(30) << nextAppointment << "|\n";
    cout << "| Bill       : Rs." << left << setw(27) << calculateBill() << "|\n";
    cout << "+--------------------------------------------+\n";
}

// ============================================================
//  FILE HANDLING
// ============================================================

// Saves Outpatient data to file
void Outpatient::save(ofstream& outFile) const {
    Patient::save(outFile);
    outFile << nextAppointment << "\n";
}

// Loads Outpatient data from file
void Outpatient::load(ifstream& inFile) {
    Patient::load(inFile);
    getline(inFile, nextAppointment);
}
