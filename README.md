# 🏦 Bank Account Management System (C++)

This project is a **C++ console-based application** that simulates a simple banking system.  
It demonstrates the use of **Object-Oriented Programming (OOP)** principles including **abstraction, inheritance, polymorphism, exception handling, and dynamic memory management**.

---

## 📖 Overview

The system allows users to create and manage savings accounts. It provides operations such as deposits, withdrawals, applying interest, and displaying account details.  
All accounts are stored dynamically using `std::vector`, ensuring scalability and flexibility.

---

## 🎮 Features

- **Account Management**
  - Create a new savings account with a unique account number
  - Display account details by account number
  - Display all existing accounts
- **Transactions**
  - Deposit money (validates positive input)
  - Withdraw money (checks sufficient balance)
- **Interest**
  - Apply fixed interest (5%) to all savings accounts
- **Menu-Driven Interface**
  - User-friendly console menu with structured options

---

## 🏗️ Class Design

### Account (Abstract Base Class)

- **Attributes**
  - `int accountNumber`
  - `std::string holderName`
  - `float balance`
- **Pure Virtual Methods**
  - `deposit(float)`
  - `withdraw(float)`
  - `displayDetails()`
  - `applyInterest()`

### SavingsAccount (Derived Class)

- Inherits from `Account`
- **Additional Attribute**
  - `float interestRate = 0.05`
- **Overrides**
  - Implements deposit and withdraw with exception handling
  - Defines `applyInterest()` to increase balance by 5%
  - Custom `displayDetails()`

### Data Management

- Uses `std::vector<Account*> accounts;`
- Enables storing multiple accounts dynamically with polymorphism.

---

## ⚙️ Implementation Highlights

- **Polymorphism** → base class pointers calling derived class methods
- **Exception Handling** → ensures robust input validation for deposits and withdrawals
- **Validation Functions**
  - `checkIfAccountExists()` → prevents duplicate accounts
  - `checkIfAccountsEmpty()` → prevents invalid operations when no accounts exist

---

## 📂 Project Structure

```
bank-account-management-system-cpp/
│
├── src/
│   └── BankSystem.cpp              # Main source code
│
├── SystemDesign(UML-Style_Plan).pdf # System design diagram
│
└── README.md
```

---

## ▶️ How to Run

Compile the program using `g++`:

```bash
g++ src/BankSystem.cpp -o BankSystem
./BankSystem
```

---

## 📸 Sample Output

```
Welcome to the Bank Account Management System
---------------------------------------------
1 -> Main Menu
2 -> Exit

*********** Main Menu ***********
1 -> Create New Account
2 -> Deposit
3 -> Withdraw
4 -> Display Details By Account Number
5 -> Display All Accounts
6 -> Apply Interest (for savings)
0 -> Opening Menu
```

---

## 🛠️ Technologies

- **Language**: C++ (C++11 standard and above)
- **Data Structures**: `std::vector` for dynamic storage
- **Concepts Used**: OOP (abstraction, inheritance, polymorphism), exception handling

---

## 📑 Documentation

- **SystemDesign(UML-Style_Plan).pdf** → High-level system design diagram

---

## 🚀 Future Improvements

- Support for multiple account types (e.g., CheckingAccount, BusinessAccount)
- File I/O for saving and loading accounts
- Extended interest rate configurations
- More advanced error handling and input validation
