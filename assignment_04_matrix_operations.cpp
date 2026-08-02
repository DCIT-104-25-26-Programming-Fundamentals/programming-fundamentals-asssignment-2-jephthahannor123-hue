// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

// ---------- Utility Functions ----------
void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// ---------- Part A: Transpose ----------
void transposeMatrix(int mat[MAX][MAX], int rows, int cols, int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

// ---------- Part B: Addition ----------
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// ---------- Part C: Multiplication ----------
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
                       int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matA[MAX][MAX], matB[MAX][MAX], result[MAX][MAX];

    // ---------------- PART A: TRANSPOSE ----------------
    cout << "===== PART A: TRANSPOSE =====" << endl;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter elements of the matrix:" << endl;
    readMatrix(matA, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matA, rows, cols);

    transposeMatrix(matA, rows, cols, result);
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(result, cols, rows);

    // ---------------- PART B: ADDITION ----------------
    cout << "\n===== PART B: ADDITION =====" << endl;
    cout << "Enter number of rows for both matrices: ";
    int addRows, addCols;
    cin >> addRows;
    cout << "Enter number of columns for both matrices: ";
    cin >> addCols;

    cout << "\nEnter elements of Matrix A:" << endl;
    readMatrix(matA, addRows, addCols);
    cout << "\nEnter elements of Matrix B:" << endl;
    readMatrix(matB, addRows, addCols);

    addMatrices(matA, matB, result, addRows, addCols);

    cout << "\nMatrix A:" << endl;
    displayMatrix(matA, addRows, addCols);
    cout << "\nMatrix B:" << endl;
    displayMatrix(matB, addRows, addCols);
    cout << "\nSum (A + B):" << endl;
    displayMatrix(result, addRows, addCols);

    // ---------------- PART C: MULTIPLICATION ----------------
    cout << "\n===== PART C: MULTIPLICATION =====" << endl;
    int rowsA, colsA, rowsB, colsB;
    cout << "Enter rows and columns of Matrix A: ";
    cin >> rowsA >> colsA;
    cout << "Enter rows and columns of Matrix B: ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB) {
        cout << "Error: Number of columns in A must equal number of rows in B." << endl;
        return 0;
    }

    cout << "\nEnter elements of Matrix A:" << endl;
    readMatrix(matA, rowsA, colsA);
    cout << "\nEnter elements of Matrix B:" << endl;
    readMatrix(matB, rowsB, colsB);

    multiplyMatrices(matA, matB, result, rowsA, colsA, colsB);

    cout << "\nMatrix A:" << endl;
    displayMatrix(matA, rowsA, colsA);
    cout << "\nMatrix B:" << endl;
    displayMatrix(matB, rowsB, colsB);
    cout << "\nProduct (A x B):" << endl;
    displayMatrix(result, rowsA, colsB);

    return 0;
}
