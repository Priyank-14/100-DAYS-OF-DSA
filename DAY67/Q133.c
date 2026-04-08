/*
Problem:
Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.

Input:
- V (vertices)
- E (edges)
- edges (u v)

Output:
- Topological order
*/

#include <stdio.h>
#include <stdlib.h>

// DFS function
void dfs(int node, int visited[], int* adj[], int size[], int stack[], int* top) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int next = adj[node][i];

        if (!visited[next]) {
            dfs(next, visited, adj, size, stack, top);
        }
    }

    // push to stack after visiting all neighbors
    stack[(*top)++] = node;
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // adjacency list
    int* adj[V];
    int size[V];

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(sizeof(int) * E);
        size[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][size[u]++] = v; // directed edge
    }

    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    int stack[V];
    int top = 0;

    // DFS for all nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, size, stack, &top);
        }
    }

    printf("Topological Order:\n");

    // print in reverse order
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}