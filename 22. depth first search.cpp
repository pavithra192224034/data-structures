#include <stdio.h>
#include <stdbool.h>
#define MAX_NODES 100
struct Graph {
    int vertices;
    int adjMatrix[MAX_NODES][MAX_NODES];
};

void initGraph(struct Graph *graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *graph, int source, int destination) {
    graph->adjMatrix[source][destination] = 1;
    graph->adjMatrix[destination][source] = 1;
}

void DFS(struct Graph *graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

int main() {
    struct Graph graph;
    int vertices, edges;
    int source, destination;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&graph, vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &source, &destination);
        addEdge(&graph, source, destination);
    }
    bool visited[MAX_NODES] = {false};
    printf("Depth First Search traversal starting from vertex 0: ");
    DFS(&graph, 0, visited);
    return 0;
}
