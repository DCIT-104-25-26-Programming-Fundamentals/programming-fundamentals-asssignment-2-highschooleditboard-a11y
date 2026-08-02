// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================

#include <iostream>
using namespace std;

void printFibonacci(int n) {
    // Validate input
    if (n <= 0) {
        cout << "Error: Please enter a positive integer." << endl;
        return;
    }

    // Generate first N terms using a loop
    long long a = 0, b = 1;
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; i++) {
        cout << a;
        if (i < n - 1) cout << " ";
        long long temp = a;
        a = b;
        b = temp + b;
    }
    cout << endl;
}

bool isFibonacci(long long number) {
    // Handle negative numbers
    if (number < 0) {
        return false;
    }

    // Generate Fibonacci numbers until we reach or pass the input
    long long a = 0, b = 1;
    while (a < number) {
        long long temp = a;
        a = b;
        b = temp + b;
    }

    // If a equals the number exactly, it's in the sequence
    return a == number;
}

int main() {
    // Part A
    cout << "PART A - First N Fibonacci Terms" << endl;
    int n;
    cout << "How many terms? ";
    cin >> n;
    printFibonacci(n);

    // Part B
    cout << "\nPART B - Fibonacci Checker" << endl;
    long long number;
    cout << "Enter a number to check: ";
    cin >> number;

    if (isFibonacci(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
