# 🛍️ OOP E-Commerce System

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey)](https://)
[![Course](https://img.shields.io/badge/Course-OOP-green.svg)](https://)

> A complete console-based E-Commerce system demonstrating core Object-Oriented Programming concepts including inheritance, polymorphism, encapsulation, operator overloading, and file I/O.

---

## 📋 Table of Contents

- [Overview](#-overview)
- [OOP Concepts Demonstrated](#-oop-concepts-demonstrated)
- [Features](#-features)
- [Project Structure](#-project-structure)
- [Installation & Usage](#-installation--usage)
- [Sample Output](#-sample-output)
- [Team](#-team)
- [Related Projects](#-related-projects)
- [Submission Details](#-submission-details)

---

## 📖 Overview

This project was developed as the final submission for **Object Oriented Programming (OOP)** course at **University of Management & Technology, Lahore** (Spring 2025).

The system simulates a complete online shopping platform with:

| Role | Capabilities |
|------|--------------|
| **Admin** | Product management, sales tracking |
| **Customer** | Registration, login, browsing, cart, checkout |

---

## 🧠 OOP Concepts Demonstrated

| Concept | Implementation | Location |
|---------|----------------|----------|
| **Encapsulation** | Private members with public getters/setters | `Product` class |
| **Inheritance** | `Admin` & `Customer` inherit from `EcommerceSystem` | Lines 150-250 |
| **Polymorphism** | Virtual destructor in base class | `~EcommerceSystem()` |
| **Operator Overloading** | `<<` operator for Product display | Friend function |
| **Static Members** | `totalProducts` counter across all instances | `Product` class |
| **Exception Handling** | Try-catch for file operations | Constructor |
| **File I/O** | Persistent storage (products.txt, users.txt, sales.txt) | Multiple methods |
| **Friend Function** | `operator<<` as friend of Product | `Product` class |

---

## 🚀 Features

### 👑 Admin Panel

| Feature | Description |
|---------|-------------|
| View Sales Records | Display all completed transactions |
| Add Product | Insert new products into catalog |
| Remove Product | Delete existing products by ID |
| View Catalog | Display all products |

### 👤 Customer Panel

| Feature | Description |
|---------|-------------|
| Register | Create new account (username/password) |
| Login | Authenticate existing user |
| Browse by Category | Electronics, Books, Furniture, Beauty, Grocery |
| Add to Cart | With stock validation |
| View Cart | Display items with running total |
| Checkout | Complete purchase → logs sale |

---

## 📁 Project Structure
OOP-Ecommerce-System/
│
├── src/
│ └── Project.cpp # Complete source code
│
├── docs/
│ └── OOP_Project_Documentation.docx
│
├── README.md # This file
└── .gitignore # Excludes .exe, .obj, etc.

---

## 🛠️ Installation & Usage

### Prerequisites

- C++ compiler (g++ recommended)
- Terminal / Command Prompt

### Compilation

**Windows (MinGW):**
```bash
g++ src/Project.cpp -o ecommerce.exe
./ecommerce.exe
### Linux / Mac
g++ src/Project.cpp -o ecommerce
./ecommerce

## Admin Access

Password: **admin123**

## Data Files Created

| File | Purpose |
|------|---------|
| products.txt | Product catalog (25 default products) |
| users.txt | Registered user credentials |
| sales.txt | Transaction records |

## Related Projects

- [DSA E-Commerce System](https://github.com/anastahir00/Ecommerce-DSA) - Same domain using Data Structures

## Submission Date

June 10, 2025
