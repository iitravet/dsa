#include <stdio.h>
#define N 4

void dfs(int graph[N][N], int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < N; i++) {
        if (graph[v][i] == 1 && !visited[i]) dfs(graph, i, visited);
    }
}

int main() {
    int graph[N][N] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 1, 0, 0}
    };
    int visited[N] = {0};
    printf("DFS: "); dfs(graph, 0, visited); printf("\n");
    return 0;
}
