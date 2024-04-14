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

Account createAccount(int accountNumber, float initialBalance) {
    if (accountNumber < 0 || initialBalance < 0) {
        printf("Invalid account number or initial balance.\n");
        exit(EXIT_FAILURE);
    }
    Account account;
    account.accountNumber = accountNumber;
    account.balance = initialBalance;
    return account;
}

void deposit(Account *account, float amount) {
    if (amount < 0) {
        printf("Invalid amount for deposit.\n");
        return;
    }
    account->balance += amount;
}

void withdraw(Account *account, float amount) {
    if (amount < 0) {
        printf("Invalid amount for withdrawal.\n");
        return;
    }
    if (amount <= account->balance) {
        account->balance -= amount;
    } else {
        printf("Insufficient balance\n");
    }
}

float getBalance(Account *account) {
    return account->balance;
}

void saveAccount(Account *account) {
    FILE *file = fopen("accounts.txt", "a");
    
    if (file != NULL) {
        fprintf(file, "%d %.2f\n", account->accountNumber, account->balance);
        fclose(file);
        printf("Account saved successfully.\n");
    } else {
        printf("Error opening file.\n");
    }
}

Account* findAccount(int accountNumber) {
    FILE *file = fopen("accounts.txt", "r");
    
    if (file != NULL) {
        Account *account = malloc(sizeof(Account));
        
        while (fscanf(file, "%d %f", &(account->accountNumber), &(account->balance)) == 2) {
            if (account->accountNumber == accountNumber) {
                fclose(file);
                return account;
            }
        }
        
        fclose(file);
        free(account);
        
        printf("Account not found.\n");
        return NULL;
        
    } else {
        printf("Error opening file.\n");
        return NULL;
    }
}

Transaction* getTransaction(int transactionId) {
    FILE *file = fopen("transactions.txt", "r");

    if (file != NULL) {
        Transaction *transaction = malloc(sizeof(Transaction));

        while (fscanf(file, "%d %d %f", &(transaction->transactionId), &(transaction->accountNumber), &(transaction->amount)) == 3) {
            if (transaction->transactionId == transactionId) {
                fclose(file);
                return transaction;
            }
        }

        fclose(file);
        free(transaction);

        printf("Transaction not found.\n");
        return NULL;

    } else {
        printf("Error opening file.\n");
        return NULL;
    }
}

void closeAccount(Account *account) {
    free(account);
    printf("Account closed successfully.\n");
}
