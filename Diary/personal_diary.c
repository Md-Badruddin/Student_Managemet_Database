
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRY_SIZE 500
#define FILE_NAME "diary.txt"

void addEntry() {
    char entry[MAX_ENTRY_SIZE];

    printf("Enter your diary entry (max 500 characters):\n");
    getchar(); // clear leftover newline
    fgets(entry, sizeof(entry), stdin);

    // timestamp
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);

    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        printf("Error: Could not open the diary file.\n");
        return;
    }
    fprintf(file, "[%s]\n%s\n\n", timestamp, entry);
    fclose(file);
    printf("Entry added successfully!\n");
}

void viewEntries() {
    char line[MAX_ENTRY_SIZE];
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("No diary entries yet.\n");
        return;
    }
    printf("\n=== Diary Entries ===\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    int choice;
    do {
        printf("\nPersonal Diary Application\n");
        printf("1. Add Diary Entry\n");
        printf("2. View Diary Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Exiting the diary application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}
