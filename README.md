# Hospital Patient Record System

A Console Application powered by OOP in C++ | Hospital Management

**Vardhaman College of Engineering — CSE Department — Summer Project 2025–26**

---

## Team

| Role | Name |
|------|------|
| **Mentor**    | [K.Shasheesh] |
| **Team Lead** | [M.Varshitha] |
| **Members**   | [R.Arun] |
|               | [Rithvik] |
|               | [Deepika] |


---

## What is this?

A fully functional hospital management system that runs in the terminal.

All patient records, doctor assignments, and appointments are managed using Object-Oriented Programming principles implemented in C++.

The project demonstrates practical usage of **Inheritance**, **Polymorphism**, **File Handling**, and **STL Containers** through a real-world hospital administration application.

---

## Features

| Feature | Description |
|---------|-------------|
| Admit Patient | Inpatient (with ward + bed) or Outpatient (consultation only) |
| Discharge Patient | Auto-generates bill with room charges and doctor fees |
| View All Patients | Displays complete list of all admitted patients |
| Search Patient | By ID or by name (partial match supported) |
| Ward Census | Shows only currently admitted inpatients with bed details |
| Book Appointment | Schedule appointment with doctor by ID |
| Cancel Appointment | Cancel existing appointment |
| View Appointments | Shows all scheduled and cancelled appointments |
| View Patient Bill | Calculates bill with GST (18%) and senior discount (10%) |
| Triage Helper | AI-like symptom checker recommending department + urgency |
| Auto Save/Load | Automatic file saving and loading across sessions |
| Doctor Assignment | Assign patients to specialized doctors |

---

## OOP Concepts Used

| Concept | Implementation |
|---------|----------------|
| Encapsulation | Private data members with public getters/setters |
| Inheritance | Inpatient and Outpatient derived from Patient base class |
| Polymorphism | Virtual calculateBill() and printRecord() functions |
| Abstraction | Patient as abstract base class with pure virtual functions |
| Operator Overloading | < and > operators for patient comparison |
| File Streams | ifstream / ofstream for data persistence |
| STL Vectors | Dynamic storage for patients, doctors, appointments |

---

## File Structure
hospital/
├── hospital_system.cpp
├── patients.txt
├── doctors.txt
├── appointments.txt
└── README.md

text

---

## How to Compile & Run

### Requirements
- C++ Compiler (GCC / MinGW / Code::Blocks / VS Code)

### Compile
```bash
g++ hospital_system.cpp -o hospital_system
Run
Linux / Mac

bash
./hospital_system
Windows

bash
hospital_system.exe
Note: Use PowerShell or Windows Terminal for best display. Command Prompt may not show box characters correctly.

##How the Application Works
The application starts and automatically loads saved data from files

User selects an operation from the main menu

All operations are performed on in-memory vectors

Patient records support both Inpatient (bed + ward) and Outpatient types

Appointments are linked to patients and doctors

Before exiting, all data is automatically saved to files

During the next launch, all previous data is restored


