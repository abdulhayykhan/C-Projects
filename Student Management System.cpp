#include <iostream>
using namespace std;

struct Student {
    string name;
    int roll;
    float percentage;
};

Student students[100];
int studentCount = 0;

void addStudent() {
    if (studentCount >= 100) {
        cout << "Student list is full!\n";
        return;
    }
    cout << "\n=== Add New Student ===\n";
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, students[studentCount].name);
    cout << "Enter Roll Number: ";
    cin >> students[studentCount].roll;
    cout << "Enter Percentage: ";
    cin >> students[studentCount].percentage;
    studentCount++;
    cout << "Student successfully added!\n";
}

void viewStudents() {
    if (studentCount == 0) {
        cout << "\nNo students available.\n";
        return;
    }
    cout << "\n=== Student Records ===\n";
    cout << "----------------------------------\n";
    cout << "Roll No. | Name           | Percentage\n";
    cout << "----------------------------------\n";
    for (int i = 0; i < studentCount; i++) {
        cout << students[i].roll << "\t  | " << students[i].name << "\t  | " << students[i].percentage << endl;
    }
    cout << "----------------------------------\n";
}

void searchStudent() {
    int rollNo;
    cout << "\n=== Search Student ===\n";
    cout << "Enter Roll Number: ";
    cin >> rollNo;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll == rollNo) {
            cout << "\nStudent Found!\n";
            cout << "-------------------------\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Roll No: " << students[i].roll << "\n";
            cout << "Percentage: " << students[i].percentage << "\n";
            cout << "-------------------------\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n=============================\n";
        cout << "  STUDENT MANAGEMENT SYSTEM  \n";
        cout << "=============================\n";
        cout << "1. Add Student\n2. View Students\n3. Search Student\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting the program...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}
