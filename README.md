# Bank_mangement_system

The Banking Management System Library is a C library that provides a simple way to manage bank accounts, perform transactions, and maintain account balances. This library offers basic banking functionalities that can be incorporated into larger financial applications.

## Project Description

The goal of this project is to create a modular and easy-to-use C library that facilitates the management of bank accounts, including features such as creating accounts, depositing funds, withdrawing funds, checking balances, and retrieving transaction details.

## Goals

- Provide a user-friendly API for interacting with bank accounts and transactions.
- Demonstrate file handling techniques for data persistence.
- Illustrate how to structure and organize a C project with multiple source files.

## Specifications

### Features

1. **Create Account:** Users can create new bank accounts by providing an account number and an initial balance.

2. **Deposit Funds:** Account holders can deposit funds into their accounts.

3. **Withdraw Funds:** Account holders can withdraw funds from their accounts, provided they have sufficient balance.

4. **Check Balance:** Users can inquire about their account balance.

5. **Retrieve Transaction Details:** Account holders can view their transaction history, including deposit and withdrawal details.

### File Handling

Account data and transaction details are stored in text files:
- Account data: `accounts.txt`
- Transaction details: `transactions.txt`

### Design

The library consists of the following components:

- `banking_system.h`: Header file containing function declarations and structures.
- `banking_system.c`: Source file implementing the banking functionalities.
- `main.c`: Example usage of the library to demonstrate its features.
- `accounts.txt`: Text file storing account data.
- `transactions.txt`: Text file storing transaction details.

## Getting Started

### Prerequisites

- C compiler (e.g., GCC)

