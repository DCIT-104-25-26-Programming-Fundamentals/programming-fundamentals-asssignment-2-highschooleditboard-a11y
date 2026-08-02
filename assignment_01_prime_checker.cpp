// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number) {
    // Numbers less than 2 are not prime
    if (number < 2) {
        return false;
    }
    // Check divisors from 2 up to the square root of the number
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is NOT a prime number." << endl;
    }

    return 0;
}
