// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        return NAN;
    }
    return a / b;
}

double modulus(double a, double b) {
    if (b == 0) {
        return NAN;
    }
    return fmod(a, b);
}

double exponentiate(double a, double b) {
    return pow(a, b);
}

void getNumbers(double &a, double &b) {
    cout << "Enter first number : ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
}

void printMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}

int main() {
    bool running = true;

    while (running) {
        printMenu();
        int choice;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            running = false;
            continue;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Invalid choice. Please enter a number between 1 and 7." << endl;
            continue;
        }

        double a, b, result;
        string symbol;
        getNumbers(a, b);

        if (choice == 1) {
            result = add(a, b);
            symbol = "+";
        } else if (choice == 2) {
            result = subtract(a, b);
            symbol = "-";
        } else if (choice == 3) {
            result = multiply(a, b);
            symbol = "*";
        } else if (choice == 4) {
            result = divide(a, b);
            symbol = "/";
        } else if (choice == 5) {
            result = modulus(a, b);
            symbol = "%";
        } else {
            result = exponentiate(a, b);
            symbol = "^";
        }

        if (isnan(result)) {
            cout << "Error: Cannot divide by zero." << endl;
        } else {
            cout << fixed << setprecision(2);
            cout << "Result: " << a << " " << symbol << " " << b << " = " << result << endl;
        }
    }

    return 0;
}
