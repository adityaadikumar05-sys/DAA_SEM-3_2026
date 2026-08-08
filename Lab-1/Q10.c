/**10. ATM Transaction System
• Create a menu-driven program to check balance, deposit money, withdraw money, and exit.
• Prevent a withdrawal when the balance is insufficient.
• Maintain and display the last five transactions. */

#include <stdio.h>

#define MAX_TRANSACTIONS 5

float balance = 1000.0;
char transactions[MAX_TRANSACTIONS][50];
int transactionCount = 0;

void addTransaction(const char* type, float amount) {
    if (transactionCount < MAX_TRANSACTIONS) {
        sprintf(transactions[transactionCount], "Type: %s, Amount: %.2f", type, amount);
        transactionCount++;
    } else {
        // Shift transactions up
        for (int i = 0; i < MAX_TRANSACTIONS - 1; i++) {
            strcpy(transactions[i], transactions[i + 1]);
        }
        sprintf(transactions[MAX_TRANSACTIONS - 1], "Type: %s, Amount: %.2f", type, amount);
    }
}

void checkBalance() {
    printf("Your current balance is: $%.2f\n", balance);
}

void deposit() {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        balance += amount;
        addTransaction("Deposit", amount);
        printf("$%.2f deposited successfully.\n", amount);
        checkBalance();
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw() {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid withdrawal amount.\n");
    } else if (amount > balance) {
        printf("Insufficient balance.\n");
    } else {
        balance -= amount;
        addTransaction("Withdrawal", amount);
        printf("$%.2f withdrawn successfully.\n", amount);
        checkBalance();
    }
}

void displayTransactions() {
    printf("\n--- Last %d Transactions ---\n", transactionCount);
    if (transactionCount == 0) {
        printf("No transactions yet.\n");
    } else {
        for (int i = 0; i < transactionCount; i++) {
            printf("%s\n", transactions[i]);
        }
    }
}

int main() {
    int choice;
    do {
        printf("\nATM Menu:\n");
        printf("1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Display Last 5 Transactions\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: checkBalance(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: displayTransactions(); break;
            case 5: printf("Thank you for using the ATM. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
