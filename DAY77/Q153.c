/*
Problem Statement:
Using DFS, check if the entire graph is connected.
If all nodes are reachable from a starting node, print "CONNECTED",
otherwise print "NOT CONNECTED".
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

    // Start DFS from node 1
    dfs(1, n);

    // Check if all nodes are visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}