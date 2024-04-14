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
