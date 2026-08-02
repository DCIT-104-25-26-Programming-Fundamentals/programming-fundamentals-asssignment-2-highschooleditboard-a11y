// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols, string name) {
    cout << "Enter " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << "  Enter element [" << r << "][" << c << "]: ";
            cin >> matrix[r][c];
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cout << setw(6) << matrix[r][c];
        }
        cout << endl;
    }
}

void transpose(int matrix[10][10], int rows, int cols) {
    int result[10][10];
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            result[c][r] = matrix[r][c];
        }
    }
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(result, cols, rows);
}

void addMatrices(int matrixA[10][10], int matrixB[10][10], int rows, int cols) {
    int result[10][10];
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            result[r][c] = matrixA[r][c] + matrixB[r][c];
        }
    }
    cout << "\nA + B:" << endl;
    displayMatrix(result, rows, cols);
}

void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int m, int n, int p) {
    int result[10][10] = {};
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < p; c++) {
            for (int k = 0; k < n; k++) {
                result[r][c] += matrixA[r][k] * matrixB[k][c];
            }
        }
    }
    cout << "\nA x B:" << endl;
    displayMatrix(result, m, p);
}

int main() {
    int rows, cols;
    int matrixA[10][10], matrixB[10][10], matrix[10][10];

    // --- Part A: Transpose ---
    cout << "========================================" << endl;
    cout << "PART A - Matrix Transpose" << endl;
    cout << "========================================" << endl;
    cout << "Enter number of rows: ";    cin >> rows;
    cout << "Enter number of columns: "; cin >> cols;
    readMatrix(matrix, rows, cols, "matrix");
    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, rows, cols);
    transpose(matrix, rows, cols);

    // --- Part B: Addition ---
    cout << "\n========================================" << endl;
    cout << "PART B - Matrix Addition" << endl;
    cout << "========================================" << endl;
    cout << "Enter number of rows: ";    cin >> rows;
    cout << "Enter number of columns: "; cin >> cols;
    readMatrix(matrixA, rows, cols, "Matrix A");
    readMatrix(matrixB, rows, cols, "Matrix B");
    cout << "\nMatrix A:" << endl;
    displayMatrix(matrixA, rows, cols);
    cout << "\nMatrix B:" << endl;
    displayMatrix(matrixB, rows, cols);
    addMatrices(matrixA, matrixB, rows, cols);

    // --- Part C: Multiplication ---
    cout << "\n========================================" << endl;
    cout << "PART C - Matrix Multiplication" << endl;
    cout << "========================================" << endl;
    int m, n, p;
    cout << "Enter rows for Matrix A: ";                          cin >> m;
    cout << "Enter columns for Matrix A (= rows for Matrix B): "; cin >> n;
    cout << "Enter columns for Matrix B: ";                       cin >> p;
    readMatrix(matrixA, m, n, "Matrix A");
    readMatrix(matrixB, n, p, "Matrix B");
    cout << "\nMatrix A:" << endl;
    displayMatrix(matrixA, m, n);
    cout << "\nMatrix B:" << endl;
    displayMatrix(matrixB, n, p);
    multiplyMatrices(matrixA, matrixB, m, n, p);

    return 0;
}
