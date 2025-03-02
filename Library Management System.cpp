#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    int id;
    bool issued;
};

Book library[100];
int bookCount = 0;

void addBook() {
    if (bookCount >= 100) {
        cout << "Library is full!\n";
        return;
    }
    cout << "\n=== Add New Book ===\n";
    cout << "Enter Book ID: ";
    cin >> library[bookCount].id;
    cin.ignore(); 
    cout << "Enter Title: ";
    getline(cin, library[bookCount].title);
    cout << "Enter Author: ";
    getline(cin, library[bookCount].author);
    library[bookCount].issued = false;
    bookCount++;
    cout << "Book added successfully!\n";
}

void viewBooks() {
    if (bookCount == 0) {
        cout << "\nNo books available.\n";
        return;
    }
    cout << "\n=== Library Books ===\n";
    cout << "-------------------------------------------\n";
    cout << "ID | Title                | Author       | Status\n";
    cout << "--------------------------------------\n";
    for (int i = 0; i < bookCount; i++) {
        cout << library[i].id << " | " << library[i].title << " | " << library[i].author << " | "
             << (library[i].issued ? "Issued" : "Available") << endl;
    }
    cout << "-------------------------------------------\n";
}

void issueBook() {
    int id;
    cout << "\nEnter Book ID to Issue: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id && !library[i].issued) {
            library[i].issued = true;
            cout << "Book issued successfully!\n";
            return;
        }
    }
    cout << "Book not found or already issued!\n";
}

void returnBook() {
    int id;
    cout << "\nEnter Book ID to Return: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id && library[i].issued) {
            library[i].issued = false;
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found or not issued!\n";
}

int main() {
    int choice;
    do {
        cout << "\n=============================\n";
        cout << "  LIBRARY MANAGEMENT SYSTEM  \n";
        cout << "=============================\n";
        cout << "1. Add Book\n2. View Books\n3. Issue Book\n4. Return Book\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ensure input buffer is cleared
        cout << "\n";
        switch (choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 5: cout << "Exiting the program...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}
