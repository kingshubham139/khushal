//Write a C program for the Implementation of Kruskal’s Minimum spanning tree algorithm
#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 7

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
    return graph;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), [](const void* a, const void* b) {
        return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
    });

    int* parent = (int*)malloc(V * sizeof(int));
    for (int v = 0; v < V; v++)
        parent[v] = -1;

    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }

    printf("Edges in the minimum spanning tree:\n");
    for (i = 0; i < e; i++)
        printf("%d - %d\n", result[i].src, result[i].dest);
}

int main() {
    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // Add other edges...

    kruskalMST(graph);

    return 0;
}
