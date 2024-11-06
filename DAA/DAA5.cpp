#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class NQueens {
private:
    int N;
    vector<vector<int>> board;

public:
    NQueens(int n) {
        N = n;
        board.resize(N, vector<int>(N, 0));
    }

    // Function to check if a queen can be placed on board[row][col]
    bool isSafe(int row, int col) {
        // Check this column on upper side
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 1) {
                return false;
            }
        }

        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    // Function to solve the N-Queens problem using backtracking
    bool solveNQueens(int row) {
        // If all queens are placed, return true
        if (row == N) {
            return true;
        }

        // Try placing this queen in all columns one by one
        for (int col = 0; col < N; col++) {
            if (isSafe(row, col)) {
                board[row][col] = 1; // Place queen
                if (solveNQueens(row + 1)) {
                    return true;
                }
                board[row][col] = 0; // Backtrack if placing queen does not lead to a solution
            }
        }

        // If no place is found for this queen, return false
        return false;
    }

    // Function to print the board
    void printSolution() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << (board[i][j] ? "Q " : ". ");
            }
            cout << endl;
        }
    }

    // Function to solve the N-Queens problem
    void solve() {
        if (solveNQueens(0)) {
            printSolution();
        } else {
            cout << "No solution exists" << endl;
        }
    }
};

int main() {
    int N;
    cout << "Enter the value of N for N-Queens: ";
    cin >> N;

    if (N == 2 || N == 3) {
        cout << "No solution exists for N = " << N << endl;
        return 0;
    }

    NQueens nQueens(N);
    nQueens.solve();

    return 0;
}