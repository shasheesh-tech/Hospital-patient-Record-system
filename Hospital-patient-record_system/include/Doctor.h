#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//============================================================
//                 Doctor Class
// Purpose:
// Stores doctor information and provides functions to
// display, save, and load doctor records.
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
    Doctor(int doctorId, string doctorName, string doctorSpecialization);

    // Getter Functions
    int getId() const;
    string getName() const;
    string getSpecialization() const;

    // Display Function
    void displayDoctor() const;

    // File Handling Functions
    void saveDoctor(ofstream &out) const;
    void loadDoctor(ifstream &in);
};

#endif
