// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Student struct definition
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Student records storage
vector<Student> students;

double calculateAverage(vector<double> scores) {
    double total = 0;
    for (int i = 0; i < scores.size(); i++) {
        total += scores[i];
    }
    return total / scores.size();
}

void addStudent() {
    Student s;

    cout << "Student name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    if (numScores <= 0) {
        cout << "Error: Number of scores must be positive." << endl;
        return;
    }

    for (int i = 1; i <= numScores; i++) {
        double score;
        cout << "Enter score " << i << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

void displayAllStudents() {
    if (students.empty()) {
        cout << "No students on record yet." << endl;
        return;
    }

    cout << "\n" << string(60, '=') << endl;
    cout << left << setw(22) << "  NAME"
         << setw(12) << "ID"
         << setw(16) << "SCORES"
         << "AVERAGE" << endl;
    cout << string(60, '=') << endl;

    for (int i = 0; i < students.size(); i++) {
        Student s = students[i];

        // Build scores string
        string scoresStr = "";
        for (int j = 0; j < s.scores.size(); j++) {
            scoresStr += to_string((int)s.scores[j]);
            if (j < s.scores.size() - 1) scoresStr += ", ";
        }

        double avg = calculateAverage(s.scores);
        cout << left
             << setw(22) << ("  " + s.name)
             << setw(12) << s.id
             << setw(16) << scoresStr
             << fixed << setprecision(2) << avg << endl;
    }

    cout << string(60, '=') << endl;
}

void calculateStudentAverage() {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    // Search for student by ID
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            double avg = calculateAverage(students[i].scores);
            cout << fixed << setprecision(2);
            cout << students[i].name << "'s average score: " << avg << endl;
            return;
        }
    }

    cout << "Error: No student found with ID " << id << "." << endl;
}

void printMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
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
            addStudent();
        } else if (choice == 2) {
            displayAllStudents();
        } else if (choice == 3) {
            calculateStudentAverage();
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            running = false;
        } else {
            cout << "Error: Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}
