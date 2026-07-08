#include "../include/Doctor.h"
#include <iomanip>

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

string Doctor::getSpec() const
{
    return specialization;
}

//============================================================
// Display Doctor Details
//============================================================

void Doctor::display() const
{
    cout << left
         << setw(5)  << id
         << setw(20) << name
         << setw(20) << specialization
         << endl;
}

//============================================================
// Save Doctor Record
//============================================================

void Doctor::save(ofstream &out) const
{
    out << id << endl;
    out << name << endl;
    out << specialization << endl;
}

//============================================================
// Load Doctor Record
//============================================================

void Doctor::load(ifstream &in)
{
    in >> id;
    in.ignore();

    getline(in, name);
    getline(in, specialization);
}
