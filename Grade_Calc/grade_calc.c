
#include <stdio.h>

int main() {
    int n;
    printf("How many subjects? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of subjects.\n");
        return 0;
    }

    float marks[100];
    if (n > 100) {
        printf("Maximum 100 subjects allowed.\n");
        return 0;
    }

    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        printf("Enter marks for subject %d (0-100): ", i + 1);
        if (scanf("%f", &marks[i]) != 1 || marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks.\n");
            return 0;
        }
        sum += marks[i];
    }

    float avg = sum / n;
    char grade;

    if (avg >= 90) grade = 'A';
    else if (avg >= 75) grade = 'B';
    else if (avg >= 60) grade = 'C';
    else if (avg >= 40) grade = 'D';
    else grade = 'F';

    printf("\nTotal Marks: %.2f\n", sum);
    printf("Average: %.2f\n", avg);
    printf("Grade: %c\n", grade);

    return 0;
}
