#include <iostream>
using namespace std;

string todoList[100];
int taskCount = 0;

void addTask() {
    if (taskCount >= 100) {
        cout << "Task list is full!\n";
        return;
    }
    cout << "\n=== Add New Task ===\n";
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, todoList[taskCount]);
    taskCount++;
    cout << "Task successfully added!\n";
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "\nNo tasks available.\n";
        return;
    }
    cout << "\n=== To-Do List ===\n";
    cout << "------------------------------\n";
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << todoList[i] << endl;
    }
    cout << "------------------------------\n";
}

void removeTask() {
    if (taskCount == 0) {
        cout << "\nNo tasks to remove.\n";
        return;
    }
    int index;
    viewTasks();
    cout << "Enter task number to remove: ";
    cin >> index;
    if (index > 0 && index <= taskCount) {
        for (int i = index - 1; i < taskCount - 1; i++) {
            todoList[i] = todoList[i + 1];
        }
        taskCount--;
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n=============================\n";
        cout << "     TO-DO LIST MANAGER    \n";
        cout << "=============================\n";
        cout << "1. Add Task\n2. View Tasks\n3. Remove Task\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";
        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: removeTask(); break;
            case 4: cout << "Exiting the program...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}
