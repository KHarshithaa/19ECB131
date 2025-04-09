#include <stdio.h>

#define N 8

int board[N][N];

// Moves a knight can make
int xMoves[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yMoves[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int isSafe(int x, int y) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}

int solveKTUtil(int x, int y, int movei) {
    if (movei == N * N)
        return 1;

    for (int k = 0; k < 8; k++) {
        int nextX = x + xMoves[k];
        int nextY = y + yMoves[k];

        if (isSafe(nextX, nextY)) {
            board[nextX][nextY] = movei;
            if (solveKTUtil(nextX, nextY, movei + 1))
                return 1;
            board[nextX][nextY] = -1; // Backtrack
        }
    }

    return 0;
}

void solveKT() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;

    board[0][0] = 0;

    if (!solveKTUtil(0, 0, 1)) {
        printf("No solution exists.\n");
        return;
    }

    printf("Knight's Tour Solution:\n");
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            printf("%2d ", board[x][y]);
        printf("\n");
    }
}

int main() {
    solveKT();
    return 0;
}
