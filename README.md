# Hospital Patient Record System

A Console Application powered by OOP in C++ | Hospital Management

**Vardhaman College of Engineering — CSE Department — Summer Project 2025–26**

---

## Team

| Role | Name |
|------|------|
| **Mentor**    | [K.shasheesh] 
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
| **Admit Patient** | Inpatient (with ward + bed) or Outpatient (consultation only) |
| **Discharge Patient** | Auto-generates bill with room charges and doctor fees |
| **View All Patients** | Displays complete list of all admitted patients |
| **Search Patient** | By ID or by name (partial match supported) |
| **Ward Census** | Shows only currently admitted inpatients with bed details |
| **Book Appointment** | Schedule appointment with doctor by ID |
| **Cancel Appointment** | Cancel existing appointment |
| **View Appointments** | Shows all scheduled and cancelled appointments |
| **View Patient Bill** | Calculates bill with GST (18%) and senior discount (10%) |
| **Triage Helper** | AI-like symptom checker recommending department + urgency |
| **Auto Save/Load** | Automatic file saving and loading across sessions |
| **Doctor Assignment** | Assign patients to specialized doctors |

---

## OOP Concepts Used

| Concept | Implementation |
|---------|----------------|
| **Encapsulation** | Private data members with public getters/setters |
| **Inheritance** | Inpatient and Outpatient derived from Patient base class |
| **Polymorphism** | Virtual calculateBill() and printRecord() functions |
| **Abstraction** | Patient as abstract base class with pure virtual functions |
| **Operator Overloading** | < and > operators for patient comparison |
| **File Streams** | ifstream / ofstream for data persistence |
| **STL Vectors** | Dynamic storage for patients, doctors, appointments |

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

---
## How the Application Works

1. The application starts and automatically loads saved data from files
2. User selects an operation from the main menu
3. All operations are performed on in-memory vectors
4. Patient records support both Inpatient (bed + ward) and Outpatient types
5. Appointments are linked to patients and doctors
6. Before exiting, all data is automatically saved to files
7. During the next launch, all previous data is restored

---

## Patient Types & Billing

### Inpatient
- Requires ward number and bed number
- Charges: ₹2000 per day (room) + ₹500 per day (doctor fee)
- GST (18%) applied
- Senior citizens (age 60+) get 10% discount

### Outpatient
- Consultation only, no bed required
- Flat fee: ₹500
- GST (18%) applied

---

## Doctors Available

| ID | Doctor Name | Specialization |
|----|-------------|----------------|
| 1 | Dr. Smith | Cardiology |
| 2 | Dr. Johnson | Neurology |
| 3 | Dr. Williams | Pediatrics |
| 4 | Dr. Patel | Orthopedics |
| 5 | Dr. Reddy | General Medicine |

---

## Triage Helper (AI-like Symptom Checker)

Describe patient symptoms, and the system recommends:

| Symptom Keyword | Department | Urgency |
|----------------|------------|---------|
| chest pain, heart | Cardiology | EMERGENCY |
| breathless, cough | Pulmonology | URGENT / NORMAL |
| fever | General Medicine | NORMAL |
| headache | Neurology | NORMAL |
| fracture | Orthopedics | URGENT |
| burn | Plastic Surgery | EMERGENCY |
| stomach | Gastroenterology | NORMAL |
| eye | Ophthalmology | NORMAL |
| child | Pediatrics | URGENT |
| pregnant | Obstetrics | URGENT |

---

## Sample Use Cases

- Hospital patient admission and discharge
- Doctor appointment scheduling
- Automated billing with tax calculation
- Emergency symptom triage
- OOP concepts demonstration project
- File handling practice project

---

## Future Improvements

- GUI version using Qt
- Database integration (MySQL/SQLite)
- Email/SMS appointment reminders
- Pharmacy inventory management
- Patient portal for online booking
- Export reports to PDF/Excel

---

## License

**Academic Project — Vardhaman College of Engineering (2025–26)**
