#include <stdio.h>

int main() {
    int choice, amount, balance = 10000;
    int transactions = 0;

    printf("========= Mini ATM Simulator =========\n");
    printf("Initial Balance: ₹%d\n", balance);

    while (transactions < 5) {
        printf("\n1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Your Current Balance: ₹%d\n", balance);
            transactions++;
        } else if (choice == 2) {
            printf("Enter amount to deposit: ");
            scanf("%d", &amount);
            if (amount > 0) {
                balance += amount;
                printf("Amount Deposited Successfully!\n");
                transactions++;
            } else {
                printf("Invalid deposit amount!\n");
            }
        } else if (choice == 3) {
            printf("Enter amount to withdraw: ");
            scanf("%d", &amount);
            if (amount > 0) {
                if (balance - amount >= 500) {
                    balance -= amount;
                    printf("Withdrawal Successful! Remaining Balance: ₹%d\n", balance);
                    transactions++;
                } else {
                    printf("Insufficient balance! Minimum ₹500 must remain.\n");
                }
            } else {
                printf("Invalid withdrawal amount!\n");
            }
        } else if (choice == 4) {
            printf("Thank you for banking with us!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    printf("\n========= Transaction Summary =========\n");
    printf("Total Transactions: %d\n", transactions);
    printf("Final Balance: ₹%d\n", balance);
    printf("Session Ended.\n");

    return 0;
}