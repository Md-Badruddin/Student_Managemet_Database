
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100

typedef struct {
    char title[TITLE_LEN];
    int  year;
} Book;

void listBooks(Book books[], int count) {
    if (count == 0) {
        printf("No books in library.\n");
        return;
    }
    printf("\nLibrary Books:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s (%d)\n", i + 1, books[i].title, books[i].year);
    }
}

void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }
    getchar(); // clear leftover newline
    printf("Enter title: ");
    fgets(books[*count].title, TITLE_LEN, stdin);
    size_t len = strlen(books[*count].title);
    if (len > 0 && books[*count].title[len - 1] == '\n')
        books[*count].title[len - 1] = '\0';
    printf("Enter year: ");
    scanf("%d", &books[*count].year);
    (*count)++;
    printf("Book added.\n");
}

void searchBook(Book books[], int count) {
    if (count == 0) {
        printf("No books to search.\n");
        return;
    }
    getchar(); // clear newline
    char query[TITLE_LEN];
    printf("Enter title to search: ");
    fgets(query, TITLE_LEN, stdin);
    size_t len = strlen(query);
    if (len > 0 && query[len - 1] == '\n')
        query[len - 1] = '\0';

    int found = 0;
    printf("\nSearch results:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, query) != NULL) {
            printf("%d. %s (%d)\n", i + 1, books[i].title, books[i].year);
            found = 1;
        }
    }
    if (!found) printf("No matching books.\n");
}

void deleteBook(Book books[], int *count) {
    if (*count == 0) {
        printf("No books to delete.\n");
        return;
    }
    int index;
    listBooks(books, *count);
    printf("Enter number of book to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > *count) {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index - 1; i < *count - 1; i++) {
        books[i] = books[i + 1];
    }
    (*count)--;
    printf("Book deleted.\n");
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Library Book Tracker ===\n");
        printf("1. List books\n");
        printf("2. Add book\n");
        printf("3. Search book\n");
        printf("4. Delete book\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            break;
        }

        switch (choice) {
            case 1: listBooks(books, count); break;
            case 2: addBook(books, &count); break;
            case 3: searchBook(books, count); break;
            case 4: deleteBook(books, &count); break;
            case 5: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
