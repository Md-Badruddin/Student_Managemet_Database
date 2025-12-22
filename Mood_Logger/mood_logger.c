
#include <stdio.h>
#include <string.h>

#define FILE_NAME "mood_log.txt"
#define NOTE_LEN 100

void addEntry() {
    int rating;
    char note[NOTE_LEN];

    printf("How was your day (1-5)? ");
    if (scanf("%d", &rating) != 1 || rating < 1 || rating > 5) {
        printf("Invalid rating.\n");
        return;
    }
    getchar(); // clear newline

    printf("Short note about your day: ");
    fgets(note, NOTE_LEN, stdin);
    size_t len = strlen(note);
    if (len > 0 && note[len - 1] == '\n')
        note[len - 1] = '\0';

    FILE *fp = fopen(FILE_NAME, "a");
    if (!fp) {
        printf("Could not open log file.\n");
        return;
    }
    fprintf(fp, "%d|%s\n", rating, note);
    fclose(fp);

    printf("Entry saved.\n");
}

void viewEntries() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) {
        printf("No entries yet.\n");
        return;
    }
    int rating;
    char note[NOTE_LEN];

    printf("\n=== Mood History ===\n");
    while (fscanf(fp, "%d|%99[^\n]\n", &rating, note) == 2) {
        printf("Rating: %d  |  Note: %s\n", rating, note);
    }
    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Daily Mood Logger ===\n");
        printf("1. Add today’s mood\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Choose option: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
