//Q.2)Write a C program that accepts the vertices and edges of a graph. Create adjacency list. 
//Implement functions to print indegree, outdegree and total degree of all vertex of graph.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V; 
    struct Node** adjacencyList; 
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjacencyList = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; ++i) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function to print indegree, outdegree, and total degree of all vertices
void printDegrees(struct Graph* graph) {
    printf("Vertex\tIndegree\tOutdegree\tTotal degree\n");

    for (int i = 0; i < graph->V; ++i) {
        int inDegree = 0, outDegree = 0;

        struct Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            inDegree++;
            current = current->next;
        }

        outDegree = inDegree; 

        int totalDegree = inDegree + outDegree;
        
        printf("%d\t%d\t\t%d\t\t%d\n", i, inDegree, outDegree, totalDegree);
    }
}

int main() {
    int V, E; 
    
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V);

    // Input the edges
    for (int i = 0; i < E; ++i) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

        printDegrees(graph);

    return 0;
}

