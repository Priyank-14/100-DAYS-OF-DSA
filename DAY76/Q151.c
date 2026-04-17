/*
Problem Statement:
Using DFS, count the number of connected components in an undirected graph.
*/

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

// DFS function
void dfs(int node, int n) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Initialize visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
    }

    int components = 0;

    // Count connected components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, n);
            components++;
        }
    }

    printf("Number of connected components: %d\n", components);

    return 0;
}