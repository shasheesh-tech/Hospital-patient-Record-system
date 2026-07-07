#include "../include/Doctor.h"

//============================================================
// Default Constructor
//============================================================

Doctor::Doctor()
{
    id = 0;
    name = "";
    specialization = "";
}

//============================================================
// Parameterized Constructor
//============================================================

Doctor::Doctor(int doctorId,
               string doctorName,
               string doctorSpecialization)
{
    id = doctorId;
    name = doctorName;
    specialization = doctorSpecialization;
}

//============================================================
// Getter Functions
//============================================================

int Doctor::getId() const
{
    return id;
}

string Doctor::getName() const
{
    return name;
}

string Doctor::getSpecialization() const
{
    return specialization;
}

//============================================================
// Display Doctor Information
//============================================================

void Doctor::displayDoctor() const
{
    cout << "--------------------------------------------\n";
    cout << "Doctor ID        : " << id << endl;
    cout << "Doctor Name      : Dr. " << name << endl;
    cout << "Specialization   : " << specialization << endl;
    cout << "--------------------------------------------\n";
}

//============================================================
// Save Doctor Information to File
//============================================================

void Doctor::saveDoctor(ofstream &out) const
{
    out << id << endl;
    out << name << endl;
    out << specialization << endl;
}

//============================================================
// Load Doctor Information from File
//============================================================

void Doctor::loadDoctor(ifstream &in)
{
    in >> id;
    in.ignore();

    getline(in, name);
    getline(in, specialization);
}
