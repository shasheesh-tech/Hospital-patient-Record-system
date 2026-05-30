#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

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
    Patient();
    Patient(int i, string n, int a, string g, string date);
    virtual ~Patient();

    // Pure virtual functions - Polymorphism
    virtual double calculateBill() const = 0;
    virtual void   printRecord()   const = 0;
    virtual string getPatientType() const = 0;

    // Operator overloading
    bool operator<(const Patient& o) const;
    bool operator>(const Patient& o) const;

    // Getters
    int    getId()            const;
    string getName()          const;
    int    getAge()           const;
    string getGender()        const;
    string getAdmissionDate() const;
    bool   isAdmitted()       const;
    int    getDoctorId()      const;

    // Setters
    void assignDoctor(int docId);
    void discharge();
    void setAdmissionDate(string date);

    // File I/O
    virtual void save(ofstream& out) const;
    virtual void load(ifstream& in);
};

#endif