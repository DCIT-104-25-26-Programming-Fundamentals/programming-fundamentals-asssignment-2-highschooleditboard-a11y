// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================

#include <iostream>
using namespace std;

double calculateSum(double numbers[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += numbers[i];
    }
    return total;
}

double calculateAverage(double numbers[], int n) {
    return calculateSum(numbers, n) / n;
}

double calculateMaximum(double numbers[], int n) {
    double maximum = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }
    return maximum;
}

double calculateMinimum(double numbers[], int n) {
    double minimum = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    return minimum;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    // Validate input
    if (n <= 0) {
        cout << "Error: Please enter a positive integer." << endl;
        return 1;
    }

    // Collect numbers from user
    double numbers[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Display results
    cout << "\nResults:" << endl;
    cout << "Sum:     " << calculateSum(numbers, n) << endl;
    cout << "Average: " << calculateAverage(numbers, n) << endl;
    cout << "Maximum: " << calculateMaximum(numbers, n) << endl;
    cout << "Minimum: " << calculateMinimum(numbers, n) << endl;

    return 0;
}
