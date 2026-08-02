// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================

#include <iostream>
using namespace std;

void printTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << number << "  x  " << i << "  =  " << number * i << endl;
    }
}

void printAllTables(int n) {
    // Validate input
    if (n <= 0) {
        cout << "Error: Please enter a positive integer." << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        printTable(i);
        // Print separator between tables, not after the last one
        if (i < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    // Part A
    cout << "PART A - Single Multiplication Table" << endl;
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number <= 0) {
        cout << "Error: Please enter a positive integer." << endl;
        return 1;
    }
    printTable(number);

    // Part B
    cout << "\nPART B - Tables from 1 to N" << endl;
    int n;
    cout << "Enter a number N: ";
    cin >> n;
    printAllTables(n);

    return 0;
}
