//Write a c program for the implimentation of topological sorting.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n, adj[MAX][MAX], visited[MAX], stack[MAX], top=-1;

void dfs(int v) {
    int i;
    visited[v] = 1;
    for (i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v;
}

void topologicalSort() {
    int i;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Topological Sort: ");
    topologicalSort();
    return 0;
}

