# 🏥 Hospital Patient Record Management System

<div align="center">
██╗  ██╗    ██████╗    ███████╗██████╗ ██╗████████╗ █████╗ ██╗
██║  ██║    ██╔═══██╗  ██╔════╝██╔══██╗██║╚══██╔══╝██╔══██╗██║
███████║    ██║   ██║  ███████╗██████╔╝██║   ██║   ███████║██║
██╔══██║    ██║   ██║  ╚════██║██╔═══╝ ██║   ██║   ██╔══██║██║
██║  ██║    ╚██████╔╝  ███████║██║     ██║   ██║   ██║  ██║███████╗
╚═╝  ╚═╝     ╚═════╝   ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝







██████╗  █████╗ ████████╗██╗███████╗███╗   ██╗████████╗
██╔══██╗██╔══██╗╚══██╔══╝██║██╔════╝████╗  ██║╚══██╔══╝
██████╔╝███████║   ██║   ██║█████╗  ██╔██╗ ██║   ██║
██╔═══╝ ██╔══██║   ██║   ██║██╔══╝  ██║╚██╗██║   ██║
██║     ██║  ██║   ██║   ██║███████╗██║ ╚████║   ██║
╚═╝     ╚═╝  ╚═╝   ╚═╝   ╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝

              RECORD SYSTEM

### A Professional Console-Based Hospital Management System built using Object-Oriented Programming in C++

**Summer Project 2025–26**

Department of Computer Science & Engineering  
Vardhaman College of Engineering

Developed using **C++**, **Object-Oriented Programming**, **File Handling**, and **STL**

</div>

---


## 📖 Project Overview

The **Hospital Patient Record Management System** is a comprehensive terminal-based application developed in **C++** that simulates the day-to-day operations of a hospital.

The system enables efficient management of patients, doctors, appointments, hospital admissions, billing, and medical records while demonstrating the practical implementation of major **Object-Oriented Programming (OOP)** concepts.

Instead of simply storing records, the application provides a structured workflow similar to a real hospital management system where doctors, patients, appointments, and billing are interconnected.

---

# ✨ Key Features

## 👨‍⚕️ Patient Management

- Admit New Patient
- Discharge Patient
- Search Patient by ID
- Search Patient by Name
- View Complete Patient Records
- View Ward-wise Patient Census

---

## 🩺 Doctor Management

- Predefined Specialist Doctors
- Assign Doctor to Patient
- View Doctor Information
- Department-wise Doctor Allocation

---

## 📅 Appointment Management

- Book Appointment
- Cancel Appointment
- View Appointment History
- Patient–Doctor Linking

---

## 💰 Billing System

- Automatic Bill Generation
- Room Charges
- Doctor Consultation Charges
- GST Calculation
- Senior Citizen Discount

---

## 🤖 Smart Triage Helper

An AI-inspired symptom recommendation system that suggests the appropriate hospital department based on patient symptoms.

Example:

| Symptoms | Recommended Department | Priority |
|----------|-----------------------|----------|
| Chest Pain | Cardiology | 🔴 Emergency |
| Fracture | Orthopedics | 🟠 Urgent |
| Fever | General Medicine | 🟢 Normal |
| Headache | Neurology | 🟢 Normal |
| Burn Injury | Plastic Surgery | 🔴 Emergency |

---

# 🎯 Objectives

The primary objectives of this project are:

- Demonstrate Object-Oriented Programming concepts
- Simulate real hospital administration
- Implement efficient record management
- Practice File Handling in C++
- Understand modular software design
- Build a real-world console application

---

# 🧠 OOP Concepts Demonstrated

| Concept | Implementation |
|----------|---------------|
| Encapsulation | Private data members with public member functions |
| Inheritance | Inpatient & Outpatient classes derived from Patient |
| Polymorphism | Virtual functions for Billing & Record Display |
| Abstraction | Abstract Patient base class |
| Operator Overloading | Patient comparison operators |
| Composition | HospitalSystem manages Patients, Doctors & Appointments |
| File Handling | Persistent storage using text files |
| STL Containers | Dynamic data management using vectors |

---

# ⚙️ Technologies Used

| Technology | Purpose |
|------------|---------|
| C++ | Core Programming Language |
| OOP | Software Design |
| STL | Data Storage |
| File Handling | Permanent Data Storage |
| VS Code | Development Environment |
| Git & GitHub | Version Control |

---

# 📂 Project Structure

```text
Hospital-Patient-Record-System/
│
├── include/
│      Patient.h
│      Doctor.h
│      Appointment.h
│      Hospital.h
│
├── src/
│      Patient.cpp
│      Doctor.cpp
│      Appointment.cpp
│      Hospital.cpp
│      main.cpp
│
├── data/
│      patients.txt
│      doctors.txt
│      appointments.txt
│
├── docs/
│      screenshots/
│
├── README.md
├── LICENSE
└── .gitignore
```

---

# 🏗️ Application Workflow

```text
                Start Program
                      │
                      ▼
            Load Saved Hospital Data
                      │
                      ▼
              Display Main Menu
                      │
      ┌───────────────┼────────────────┐
      ▼               ▼                ▼
 Patient Module   Doctor Module   Appointment Module
      │               │                │
      └───────────────┼────────────────┘
                      ▼
             Billing & Reports
                      │
                      ▼
              Save All Data
                      │
                      ▼
                  Exit Program
```

---

# 📸 Application Preview

### Main Menu

> *(Add terminal screenshot here)*

---

### Patient Record

> *(Add screenshot here)*

---

### Billing System

> *(Add screenshot here)*

---

### Appointment Module

> *(Add screenshot here)*

---

# 💾 Data Persistence

The project automatically stores all hospital information using text files.

- patients.txt
- doctors.txt
- appointments.txt

Whenever the application starts, previous records are automatically restored.

---

# 🏥 Billing Rules

### Inpatient

- ₹2000 per day Room Charge
- ₹500 per day Doctor Fee
- 18% GST
- 10% Senior Citizen Discount (Age ≥ 60)

---

### Outpatient

- Flat Consultation Fee
- 18% GST

---

# 🚀 Future Improvements

- Login Authentication
- Admin Dashboard
- Pharmacy Management
- Laboratory Management
- Blood Bank Module
- MySQL Database Integration
- PDF Bill Generation
- QR Code Patient ID
- GUI Version using Qt
- Online Appointment Portal

---

# 👨‍💻 Development Team

| Role | Name |
|------|------|
| Mentor | **K. Shasheesh** |
| Team Lead | **M. Varshitha** |
| Member | **R. Arun** |
| Member | **Rithvik** |
| Member | **Deepika** |

---

# 🎓 Academic Information

**Course:** Summer Project (2025–26)

**Department:** Computer Science & Engineering

**Institution:** Vardhaman College of Engineering

---

# 📜 License

This project is developed **solely for academic and educational purposes** as part of the Summer Project 2025–26 at **Vardhaman College of Engineering**.

---

<div align="center">

### ⭐ If you like this project, consider giving it a Star!

Made with ❤️ using C++

</div>

---




