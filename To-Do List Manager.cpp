#include <iostream>
using namespace std;

string todoList[100];
int taskCount = 0;

void addTask() {
    if (taskCount >= 100) {
        cout << "Task list is full!\n";
        return;
    }
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, todoList[taskCount]);
    taskCount++;
    cout << "Task added!\n";
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "To-Do List:\n";
    for (int i = 0; i < taskCount; i++)
        cout << i + 1 << ". " << todoList[i] << endl;
}

void removeTask() {
    if (taskCount == 0) {
        cout << "No tasks to remove.\n";
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
        cout << "Task removed!\n";
    } else {
        cout << "Invalid index!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "1. Add Task\n2. View Tasks\n3. Remove Task\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: removeTask(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    return 0;
}
