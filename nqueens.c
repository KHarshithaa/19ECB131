#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int board[MAX];

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void printSolution(int n) {
    int i, j;
    static int count = 1;
    printf("\nSolution %d:\n", count++);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
}

void solveNQueens(int row, int n) {
    int col;
    if (row == n) {
        printSolution(n);
        return;
    }

    for (col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solveNQueens(row + 1, n);
            // No need to "unmark" because we overwrite board[row] in the next iteration
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens (1 to %d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid input. Please enter between 1 and %d.\n", MAX);
        return 1;
    }

    solveNQueens(0, n);
    return 0;
}
