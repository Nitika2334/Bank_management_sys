#include <stdio.h>
#include <stdlib.h>
#include "banking_system.h"

int main() {
    int choice;
    int accountNumber;
    float amount;
    Account *account = NULL;

    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Save Account\n");
        printf("6. Find Account\n");
        printf("7. Get Transaction\n");
        printf("8. Close Account\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear the input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter initial balance: ");
                scanf("%f", &amount);

                if (account != NULL) {
                    free(account); // Free existing account if it exists
                }

                account = malloc(sizeof(Account));
                *account = createAccount(accountNumber, amount);

                printf("Account created successfully.\n");
                break;
            case 2:
                if (account == NULL) {
                    printf("Please create an account first.\n");
                } else {
                    printf("Enter deposit amount: ");
                    scanf("%f", &amount);
                    deposit(account, amount);
                    printf("Deposit successful.\n");
                }
                break;
            case 3:
                if (account == NULL) {
                    printf("Please create an account first.\n");
                } else {
                    printf("Enter withdrawal amount: ");
                    scanf("%f", &amount);
                    withdraw(account, amount);
                    printf("Withdrawal successful.\n");
                }
                break;
            case 4:
                if (account == NULL) {
                    printf("Please create an account first.\n");
                } else {
                    printf("Account balance: %.2f\n", getBalance(account));
                }
                break;
            case 5:
                if (account == NULL) {
                    printf("Please create an account first.\n");
                } else {
                    saveAccount(account);
                }
                break;
            case 7:
                if (account == NULL) {
                    printf("Please create an account first.\n");
                } else {
                    // Prompt the user for transaction details
                    printf("Enter transaction ID: ");
                    int transactionId;
                    scanf("%d", &transactionId);

                    // Declare the transaction variable
                    Transaction* transaction;

                    // Call the function to get the transaction
                    transaction = getTransaction(transactionId);

                    if (transaction != NULL) {
                        // Display transaction details
                        printf("Transaction ID: %d\n", transaction->transactionId);
                        printf("Account Number: %d\n", transaction->accountNumber);
                        printf("Amount: %.2f\n", transaction->amount);
                    } else {
                        printf("Transaction not found.\n");
                    }

                    // Free memory if needed
                    free(transaction);
                }
                break;
            case 8:
                if (account == NULL) {
                    printf("Please create an account first.\n");
                } else {
                    closeAccount(account);
                    account = NULL; // Set account to NULL after closing it
                }
                break;
            case 9:
                // Free the allocated memory for account before exiting
                if (account != NULL) {
                    free(account);
                }
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}






