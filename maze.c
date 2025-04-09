#include <stdio.h>

#define N 5

int maze[N][N] = {
    {1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 0, 1, 0},
    {1, 1, 1, 1, 0},
    {0, 0, 0, 1, 1}
};

int solution[N][N];

int isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

int solveMaze(int x, int y) {
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return 1;
    }

    if (isSafe(x, y)) {
        solution[x][y] = 1;

        if (solveMaze(x + 1, y)) return 1; // Move down
        if (solveMaze(x, y + 1)) return 1; // Move right

        solution[x][y] = 0; // Backtrack
        return 0;
    }

    return 0;
}

void printSolution() {
    printf("\nPath through the maze:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < N; i++) // Clear solution matrix
        for (int j = 0; j < N; j++)
            solution[i][j] = 0;

    if (solveMaze(0, 0))
        printSolution();
    else
        printf("No path found through the maze.\n");

    return 0;
}
