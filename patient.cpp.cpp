#include "Patient.h"

// ============================================================
//  PATIENT CLASS IMPLEMENTATION
//  Contributed by: Varshitha (Team Lead)
// ============================================================

Patient::Patient() : id(0), name(""), age(0), gender(""),
    admissionDate(""), admitted(false), assignedDoctorId(-1) {}

Patient::Patient(int i, string n, int a, string g, string date)
    : id(i), name(n), age(a), gender(g),
    admissionDate(date), admitted(true), assignedDoctorId(-1) {}

Patient::~Patient() {}

// Operator overloading
bool Patient::operator<(const Patient& o) const { return id < o.id; }
bool Patient::operator>(const Patient& o) const { return id > o.id; }

// Getters
int    Patient::getId()            const { return id; }
string Patient::getName()          const { return name; }
int    Patient::getAge()           const { return age; }
string Patient::getGender()        const { return gender; }
string Patient::getAdmissionDate() const { return admissionDate; }
bool   Patient::isAdmitted()       const { return admitted; }
int    Patient::getDoctorId()      const { return assignedDoctorId; }

// Setters
void Patient::assignDoctor(int docId) { assignedDoctorId = docId; }
void Patient::discharge()             { admitted = false; }
void Patient::setAdmissionDate(string date) { admissionDate = date; }

// File I/O
void Patient::save(ofstream& out) const {
    out << id << "\n" << name << "\n" << age << "\n"
        << gender << "\n" << admissionDate << "\n"
        << admitted << "\n" << assignedDoctorId << "\n";
}

void Patient::load(ifstream& in) {
    in >> id; in.ignore();
    getline(in, name);
    in >> age; in.ignore();
    getline(in, gender);
    getline(in, admissionDate);
    in >> admitted >> assignedDoctorId; in.ignore();
}