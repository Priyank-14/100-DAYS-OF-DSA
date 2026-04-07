/*
Problem:
Detect cycle in directed graph using DFS and recursion stack.

Input:
- V (vertices)
- E (edges)
- edges (u v)

Output:
- YES if cycle exists, otherwise NO
*/

#include <stdio.h>
#include <stdlib.h>

// DFS function
int dfs(int node, int visited[], int recStack[], int* adj[], int size[]) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int adjVertex = adj[node][i];

        if (!visited[adjVertex]) {
            if (dfs(adjVertex, visited, recStack, adj, size))
                return 1;
        }
        else if (recStack[adjVertex]) {
            return 1; // cycle detected
        }
    }

    recStack[node] = 0; // backtrack
    return 0;
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

    int visited[V], recStack[V];

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int hasCycle = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj, size)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}