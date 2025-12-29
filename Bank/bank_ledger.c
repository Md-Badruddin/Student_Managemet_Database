
#include <stdio.h>
#include <string.h>

#define FILE_NAME "ledger.txt"
#define LINE_LEN 100

double loadBalance() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return 0.0; // no file yet => balance 0
    double lastBalance = 0.0;
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, fp)) {
        // Format: TYPE amount balance
        char type[10];
        double amt, bal;
        if (sscanf(line, "%9s %lf %lf", type, &amt, &bal) == 3) {
            lastBalance = bal;
        }
    }
    fclose(fp);
    return lastBalance;
}

void addTransaction(const char *type, double amount, double newBalance) {
    FILE *fp = fopen(FILE_NAME, "a");
    if (!fp) {
        printf("Error: cannot open ledger file.\n");
        return;
    }
    fprintf(fp, "%s %.2f %.2f\n", type, amount, newBalance);
    fclose(fp);
}

void showHistory() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No transactions yet.\n");
        return;
    }
    char type[10];
    double amt, bal;
    printf("\nType       Amount    Balance\n");
    printf("------------------------------\n");
    while (fscanf(fp, "%9s %lf %lf", type, &amt, &bal) == 3) {
        printf("%-10s %-8.2f %-8.2f\n", type, amt, bal);
    }
    fclose(fp);
}

int main() {
    int choice;
    double balance = loadBalance();

    while (1) {
        printf("\n=== Simple Bank Ledger ===\n");
        printf("Current balance: %.2f\n", balance);
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. View history\n");
        printf("4. Exit\n");
        printf("Choose option: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            double amt;
            printf("Deposit amount: ");
            if (scanf("%lf", &amt) != 1 || amt <= 0) {
                printf("Invalid amount.\n");
                continue;
            }
            balance += amt;
            addTransaction("DEPOSIT", amt, balance);
            printf("Deposited. New balance: %.2f\n", balance);
        } else if (choice == 2) {
            double amt;
            printf("Withdraw amount: ");
            if (scanf("%lf", &amt) != 1 || amt <= 0) {
                printf("Invalid amount.\n");
                continue;
            }
            if (amt > balance) {
                printf("Not enough balance.\n");
                continue;
            }
            balance -= amt;
            addTransaction("WITHDRAW", amt, balance);
            printf("Withdrawn. New balance: %.2f\n", balance);
        } else if (choice == 3) {
            showHistory();
        } else if (choice == 4) {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid option.\n");
        }
    }
    return 0;
}
