// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task storage
vector<string> tasks;

void addTask() {
    string task;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks yet. Your to-do list is empty." << endl;
        return;
    }
    cout << "Your Tasks:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

void deleteTask() {
    if (tasks.empty()) {
        cout << "No tasks to delete." << endl;
        return;
    }
    viewTasks();
    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string removed = tasks[taskNumber - 1];
    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task \"" << removed << "\" has been removed." << endl;
}

void printMenu() {
    cout << "\n============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    bool running = true;

    while (running) {
        printMenu();
        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addTask();
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            deleteTask();
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            running = false;
        } else {
            cout << "Error: Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}
