#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int source, destination, weight;
};
struct Graph {
    int V, E;
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}
void sortEdges(struct Graph* graph) {
    for (int i = 0; i < graph->E - 1; i++) {
        for (int j = 0; j < graph->E - i - 1; j++) {
            if (graph->edge[j].weight > graph->edge[j + 1].weight) {
                struct Edge temp = graph->edge[j];
                graph->edge[j] = graph->edge[j + 1];
                graph->edge[j + 1] = temp;
            }
        }
    }
}

int findParent(int parent[], int vertex) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent, parent[vertex]);
}

void unionSets(int parent[], int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}

int kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = -1;
    sortEdges(graph);
    int edgeCount = 0;
    int i = 0;
    int totalSpanningWeight = 0;
    while (edgeCount < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edge[i++];
        int x = findParent(parent, nextEdge.source);
        int y = findParent(parent, nextEdge.destination);
        if (x != y) {
            result[edgeCount++] = nextEdge;
            totalSpanningWeight += nextEdge.weight;
            unionSets(parent, x, y);
        }
    }
    printf("Edges in MST:\n");
    for (int i = 0; i < edgeCount; i++) {
        printf("%d -- %d, Weight: %d\n", result[i].source, result[i].destination, result[i].weight);
    }
    return totalSpanningWeight;
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    struct Graph* graph = createGraph(V, E);
    printf("Enter edge details (source destination weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);
    }
    int totalSpanningWeight = kruskalMST(graph);
    printf("Total Spanning Weight: %d\n", totalSpanningWeight);
    return 0;
}
