#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// ============================================================
//  ABSTRACT BASE CLASS: Patient
//  Purpose: Blueprint for all patient types
//  Contributed by: Varshitha (Team Lead)
// ============================================================

class Patient {
protected:
    int    id;              // Patient's unique ID
    string name;            // Patient's full name
    int    age;             // Patient's age
    string gender;          // Patient's gender (M/F)
    string admissionDate;   // Date when patient was admitted
    bool   admitted;        // True if patient is currently admitted
    int    assignedDoctorId; // ID of doctor assigned to patient

public:
    // ============================================================
    //  CONSTRUCTORS & DESTRUCTOR
    //  Purpose: Create and destroy patient objects
    // ============================================================
    
    // Default constructor
    Patient();
    
    // Parameterized constructor
    Patient(int patientId, string patientName, int patientAge, 
            string patientGender, string date);
    
    // Virtual destructor
    virtual ~Patient();

    // ============================================================
    //  PURE VIRTUAL FUNCTIONS (Polymorphism)
    //  Purpose: Must be implemented by child classes
    // ============================================================
    
    // Calculates bill - different for Inpatient and Outpatient
    virtual double calculateBill() const = 0;
    
    // Prints patient record - different formatting for each type
    virtual void printRecord() const = 0;
    
    // Returns patient type - "Inpatient" or "Outpatient"
    virtual string getPatientType() const = 0;

    // ============================================================
    //  OPERATOR OVERLOADING
    //  Purpose: Compare patients by ID
    // ============================================================
    
    // Less than operator - compares IDs
    bool operator<(const Patient& otherPatient) const;
    
    // Greater than operator - compares IDs
    bool operator>(const Patient& otherPatient) const;

    // ============================================================
    //  GETTER FUNCTIONS
    //  Purpose: Access private data
    // ============================================================
    
    int    getId()            const;
    string getName()          const;
    int    getAge()           const;
    string getGender()        const;
    string getAdmissionDate() const;
    bool   isAdmitted()       const;
    int    getDoctorId()      const;

    // ============================================================
    //  SETTER FUNCTIONS
    //  Purpose: Modify private data
    // ============================================================
    
    // Assigns a doctor to this patient
    void assignDoctor(int docId);
    
    // Discharges patient (sets admitted to false)
    void discharge();
    
    // Sets admission date
    void setAdmissionDate(string date);

    // ============================================================
    //  FILE HANDLING FUNCTIONS
    //  Purpose: Save and load patient data
    // ============================================================
    
    // Writes patient data to file
    virtual void save(ofstream& outFile) const;
    
    // Reads patient data from file
    virtual void load(ifstream& inFile);
};

// ============================================================
//  DERIVED CLASS: Inpatient
//  Purpose: Represents patient who stays overnight in hospital
//  Contributed by: Arun
// ============================================================

class Inpatient : public Patient {
private:
    int wardNumber;     // Ward where patient is staying
    int bedNumber;      // Bed number in the ward
    int daysAdmitted;   // Number of days admitted

public:
    // ============================================================
    //  CONSTRUCTORS
    // ============================================================
    
    Inpatient();
    Inpatient(int patientId, string patientName, int patientAge,
              string patientGender, string date, int ward, int bed);

    // ============================================================
    //  SETTER & GETTER FUNCTIONS
    // ============================================================
    
    void setDays(int days);
    int  getWard() const;
    int  getBed()  const;
    int  getDays() const;

    // ============================================================
    //  OVERRIDDEN VIRTUAL FUNCTIONS
    //  Purpose: Provide Inpatient-specific implementation
    // ============================================================
    
    // Calculates bill: ₹2000/day room + ₹500/day doctor fee
    double calculateBill() const override;
    
    // Returns "Inpatient"
    string getPatientType() const override;
    
    // Prints Inpatient record with ward and bed details
    void printRecord() const override;

    // ============================================================
    //  FILE HANDLING
    // ============================================================
    
    void save(ofstream& outFile) const override;
    void load(ifstream& inFile) override;
};

// ============================================================
//  DERIVED CLASS: Outpatient
//  Purpose: Represents patient who visits for consultation only
//  Contributed by: Arun
// ============================================================

class Outpatient : public Patient {
private:
    string nextAppointment;  // Date of next appointment

public:
    // ============================================================
    //  CONSTRUCTORS
    // ============================================================
    
    Outpatient();
    Outpatient(int patientId, string patientName, int patientAge,
               string patientGender, string date, string nextApp);

    // ============================================================
    //  GETTER FUNCTIONS
    // ============================================================
    
    string getNextAppointment() const;

    // ============================================================
    //  OVERRIDDEN VIRTUAL FUNCTIONS
    //  Purpose: Provide Outpatient-specific implementation
    // ============================================================
    
    // Calculates bill: flat ₹500 consultation fee
    double calculateBill() const override;
    
    // Returns "Outpatient"
    string getPatientType() const override;
    
    // Prints Outpatient record with appointment details
    void printRecord() const override;

    // ============================================================
    //  FILE HANDLING
    // ============================================================
    
    void save(ofstream& outFile) const override;
    void load(ifstream& inFile) override;
};

#endif