#include <stdio.h>
#include <stdbool.h>
#include <limits.h> 
#define V 10 
int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V], int n) {
    printf("Edge \tWeight\n");
    int totalWeight = 0; 
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]]; 
    }
    printf("Total Spanning Tree Weight: %d\n", totalWeight); 
}


void primMST(int graph[V][V], int n) {
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, n);
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int graph[V][V];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    primMST(graph, n);
    return 0;
}
