#include <stdio.h>
#include <stdlib.h>

typedef struct { int u, v, weight; } Edge;
int parent[100];

int find(int i) {
    while (parent[i] == i) return i;
    return find(parent[i]);
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskalMST(Edge edges[], int V, int E) {
    for (int i = 0; i < V; i++) parent[i] = i;
    qsort(edges, E, sizeof(Edge), compare);
    
    int mst_cost = 0;
    printf("MST Edges:\n");
    for (int i = 0; i < E; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);
        if (u != v) {
            printf("%d - %d (Cost: %d)\n", edges[i].u, edges[i].v, edges[i].weight);
            mst_cost += edges[i].weight;
            unionSet(u, v);
        }
    }
    printf("Total Cost: %d\n", mst_cost);
}

int main() {
    int V = 4, E = 5;
    Edge edges[] = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    kruskalMST(edges, V, E);
    return 0;
}
