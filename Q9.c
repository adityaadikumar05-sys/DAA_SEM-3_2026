/**9. Library Book Management
• Store the book ID, title, author, total copies, and available copies using structures.
• Create a menu-driven program to add and search for books, issue and return books, and display
all books currently unavailable. */


#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int totalCopies;
    int availableCopies;
};

struct Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full.\n");
        return;
    }
    printf("Enter Book ID: ");
    scanf("%d", &library[bookCount].id);
    printf("Enter Title: ");
    scanf(" %[^\n]s", library[bookCount].title);
    printf("Enter Author: ");
    scanf(" %[^\n]s", library[bookCount].author);
    printf("Enter Total Copies: ");
    scanf("%d", &library[bookCount].totalCopies);
    library[bookCount].availableCopies = library[bookCount].totalCopies;
    bookCount++;
    printf("Book added successfully.\n");
}

void searchBook() {
    char title[100];
    printf("Enter title to search: ");
    scanf(" %[^\n]s", title);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Book Found: ID: %d, Author: %s, Available: %d/%d\n",
                   library[i].id, library[i].author, library[i].availableCopies, library[i].totalCopies);
            return;
        }
    }
    printf("Book not found.\n");
}

void issueBook() {
    int id;
    printf("Enter Book ID to issue: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (library[i].availableCopies > 0) {
                library[i].availableCopies--;
                printf("Book issued successfully.\n");
            } else {
                printf("Book is currently unavailable.\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            if (library[i].availableCopies < library[i].totalCopies) {
                library[i].availableCopies++;
                printf("Book returned successfully.\n");
            } else {
                printf("All copies are already available.\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

void displayUnavailable() {
    printf("\n--- Currently Unavailable Books ---\n");
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].availableCopies == 0) {
            printf("ID: %d, Title: %s, Author: %s\n", library[i].id, library[i].title, library[i].author);
            found = 1;
        }
    }
    if (!found) {
        printf("All books are available.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nLibrary Menu:\n");
        printf("1. Add Book\n2. Search Book\n3. Issue Book\n4. Return Book\n5. Display Unavailable Books\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: displayUnavailable(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}
