#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int accountNumber;
    float balance;
} Account;

typedef struct {
    int transactionId;
    int accountNumber;
    float amount;
} Transaction;


Account createAccount(int accountNumber, float initialBalance);
void deposit(Account *account, float amount);
void withdraw(Account *account, float amount);
float getBalance(Account *account);
void saveAccount(Account *account);
Account* findAccount(int accountNumber);
Transaction* getTransaction(int transactionId);
void closeAccount(Account *account);

#endif /* ACCOUNT_H */
