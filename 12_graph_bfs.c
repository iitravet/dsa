#include <stdio.h>
#define N 4

void bfs(int graph[N][N], int start) {
    int visited[N] = {0}, queue[N], front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    
    printf("BFS: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        for (int i = 0; i < N; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[N][N] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 0},
        {0, 1, 0, 0}
    };
    bfs(graph, 0);
    return 0;
}
