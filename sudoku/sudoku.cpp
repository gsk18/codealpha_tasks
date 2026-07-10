#include <iostream>

using namespace std;

const int SIZE = 9;

// Function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]) {
    cout << "\nSolved Sudoku:\n\n";

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if a number can be placed in a given cell
bool isSafe(int board[SIZE][SIZE], int row, int col, int num) {

    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num)
            return false;
    }

    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num)
            return false;
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// Solve Sudoku using Backtracking
bool solveSudoku(int board[SIZE][SIZE]) {

    int row = -1, col = -1;
    bool foundEmpty = false;

    // Find an empty cell
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                foundEmpty = true;
                break;
            }
        }
        if (foundEmpty)
            break;
    }

    // No empty cell means puzzle is solved
    if (!foundEmpty)
        return true;

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {

        if (isSafe(board, row, col, num)) {

            board[row][col] = num;

            if (solveSudoku(board))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int board[SIZE][SIZE];

    cout << "=====================================\n";
    cout << "         SUDOKU SOLVER\n";
    cout << "=====================================\n";
    cout << "Enter the Sudoku puzzle.\n";
    cout << "Use 0 for empty cells.\n";
    cout << "Enter 9 numbers for each row separated by spaces.\n\n";

    // Input Sudoku
    for (int i = 0; i < SIZE; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
        }
    }

    cout << "\nOriginal Sudoku:\n\n";

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    if (solveSudoku(board)) {
        printBoard(board);
    } else {
        cout << "\nNo solution exists for the given Sudoku.\n";
    }

    return 0;
}