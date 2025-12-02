
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define FILE_NAME "students.txt"

typedef struct {
    char name[NAME_LEN];
    int  roll;
    float marks;
} Student;

void loadStudents(Student s[], int *count) {
    FILE *fp = fopen(FILE_NAME, "r");
    *count = 0;
    if (!fp) return;

    while (*count < MAX_STUDENTS &&
           fscanf(fp, "%d,%49[^,],%f\n",
                  &s[*count].roll, s[*count].name, &s[*count].marks) == 3) {
        (*count)++;
    }
    fclose(fp);
}

void saveStudents(Student s[], int count) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) {
        printf("Could not open file to save.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
    fclose(fp);
}

void listStudents(Student s[], int count) {
    if (count == 0) {
        printf("No students stored.\n");
        return;
    }
    printf("\n%-5s %-20s %-6s\n", "Roll", "Name", "Marks");
    printf("---------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-6.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}

void addStudent(Student s[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("List is full.\n");
        return;
    }
    Student st;
    printf("Enter roll: ");
    scanf("%d", &st.roll);
    getchar(); // clear newline
    printf("Enter name: ");
    fgets(st.name, NAME_LEN, stdin);
    size_t len = strlen(st.name);
    if (len > 0 && st.name[len - 1] == '\n')
        st.name[len - 1] = '\0';
    printf("Enter marks: ");
    scanf("%f", &st.marks);
    s[*count] = st;
    (*count)++;
    printf("Student added.\n");
}

void searchByRoll(Student s[], int count) {
    if (count == 0) {
        printf("No data to search.\n");
        return;
    }
    int roll;
    printf("Enter roll to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("Found: %d | %s | %.2f\n", s[i].roll, s[i].name, s[i].marks);
            return;
        }
    }
    printf("No student with that roll.\n");
}

void deleteByRoll(Student s[], int *count) {
    if (*count == 0) {
        printf("No data to delete.\n");
        return;
    }
    int roll, idx = -1;
    printf("Enter roll to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < *count; i++) {
        if (s[i].roll == roll) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        printf("No student with that roll.\n");
        return;
    }
    for (int i = idx; i < *count - 1; i++) {
        s[i] = s[i + 1];
    }
    (*count)--;
    printf("Student deleted.\n");
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    loadStudents(students, &count);

    while (1) {
        printf("\n=== Student Marks Manager ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Search by roll\n");
        printf("4. Delete by roll\n");
        printf("5. Save & Exit\n");
        printf("Choose option: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1: listStudents(students, count); break;
            case 2: addStudent(students, &count); break;
            case 3: searchByRoll(students, count); break;
            case 4: deleteByRoll(students, &count); break;
            case 5:
                saveStudents(students, count);
                printf("Saved to %s. Bye!\n", FILE_NAME);
                return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
