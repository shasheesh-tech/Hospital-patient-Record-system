#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//============================================================
//                Doctor Class
//------------------------------------------------------------
// Stores doctor information including:
// • Doctor ID
// • Doctor Name
// • Specialization
//
// Also provides functions for:
// • Displaying doctor details
// • Saving doctor records
// • Loading doctor records
//============================================================

class Doctor
{
private:
    int id;
    string name;
    string specialization;

public:

    // Constructors
    Doctor();
    Doctor(int id, string name, string specialization);

    // Getter Functions
    int getId() const;
    string getName() const;
    string getSpec() const;

    // Display Function
    void display() const;

    // File Handling
    void save(ofstream &out) const;
    void load(ifstream &in);
};

#endif
