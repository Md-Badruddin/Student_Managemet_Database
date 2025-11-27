
#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LEN 100
#define FILE_NAME "tasks.txt"

void loadTasks(char tasks[][MAX_LEN], int *count) {
    FILE *fp = fopen(FILE_NAME, "r");
    *count = 0;
    if (!fp) return;
    while (*count < MAX_TASKS && fgets(tasks[*count], MAX_LEN, fp)) {
        size_t len = strlen(tasks[*count]);
        if (len > 0 && tasks[*count][len - 1] == '\n')
            tasks[*count][len - 1] = '\0';
        (*count)++;
    }
    fclose(fp);
}

void saveTasks(char tasks[][MAX_LEN], int count) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) {
        printf("Error: could not open file to save.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", tasks[i]);
    }
    fclose(fp);
}

void listTasks(char tasks[][MAX_LEN], int count) {
    if (count == 0) {
        printf("No tasks yet.\n");
        return;
    }
    printf("\nYour Tasks:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void addTask(char tasks[][MAX_LEN], int *count) {
    if (*count >= MAX_TASKS) {
        printf("Task list is full.\n");
        return;
    }
    printf("Enter new task: ");
    getchar(); // clear leftover newline
    fgets(tasks[*count], MAX_LEN, stdin);
    size_t len = strlen(tasks[*count]);
    if (len > 0 && tasks[*count][len - 1] == '\n')
        tasks[*count][len - 1] = '\0';
    (*count)++;
    printf("Task added.\n");
}

void deleteTask(char tasks[][MAX_LEN], int *count) {
    if (*count == 0) {
        printf("No tasks to delete.\n");
        return;
    }
    int index;
    listTasks(tasks, *count);
    printf("Enter task number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > *count) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index - 1; i < *count - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    (*count)--;
    printf("Task deleted.\n");
}

int main() {
    char tasks[MAX_TASKS][MAX_LEN];
    int count = 0;
    int choice;

    loadTasks(tasks, &count);

    while (1) {
        printf("\n=== C To-Do List Manager ===\n");
        printf("1. List tasks\n");
        printf("2. Add task\n");
        printf("3. Delete task\n");
        printf("4. Save & Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 0;
        }

        switch (choice) {
            case 1:
                listTasks(tasks, count);
                break;
            case 2:
                addTask(tasks, &count);
                break;
            case 3:
                deleteTask(tasks, &count);
                break;
            case 4:
                saveTasks(tasks, count);
                printf("Tasks saved. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
