#include <stdio.h>
#define N 4

void createGraph(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 0;
        }
    }
    matrix[0][1] = 1; matrix[1][0] = 1;
    matrix[1][2] = 1; matrix[2][1] = 1;
}

void display(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main() {
    int graph[N][N];
    createGraph(graph);
    display(graph);
    return 0;
}
