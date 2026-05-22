# 🛍️ OOP E-Commerce System

## 📌 Course Project
**Object Oriented Programming (OOP)** - Spring 2025  
**University of Management & Technology, Lahore**  
**Instructor:** Sir Muzahir Saleem

## 👥 Team
- Muhammad Anas Tahir (F2024266985)
- Zohaib Ahmad (F2024266251)
- Muhammad Talha Bhatti (F2024266503)

## 🚀 Features

### Admin Panel
- Add/Remove products
- View sales records
- Manage product catalog

### Customer Panel
- User registration & login
- Browse products by category (Tech, Books, Furniture, Beauty, Grocery)
- Add to cart with stock validation
- Checkout with sales logging

## 🧠 OOP Concepts Demonstrated

| Concept | Implementation |
|---------|----------------|
| **Encapsulation** | Private members with public getters/setters |
| **Inheritance** | `Admin` & `Customer` inherit from `EcommerceSystem` |
| **Polymorphism** | Virtual destructor in base class |
| **Operator Overloading** | `<<` operator for Product display |
| **Static Members** | `totalProducts` counter |
| **Exception Handling** | Try-catch for file operations |
| **File I/O** | Persistent storage (products.txt, users.txt, sales.txt) |
| **Friend Function** | `operator<<` as friend |

## 🛠️ How to Run

```bash
g++ Project.cpp -o ecommerce.exe
./ecommerce.exe
