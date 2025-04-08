#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int vertices;

void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    vertices = 5;

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[2][4] = 1;

    printf("DFS starting from vertex 0: ");
    dfs(0);
    return 0;
}
