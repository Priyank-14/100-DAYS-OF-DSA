/*
Problem Statement:
Find all critical connections (bridges) in an undirected graph.
A bridge is an edge whose removal increases the number of connected components.

(Using Tarjan’s Algorithm - DFS with discovery & low time)
*/

#include <stdio.h>
#include <stdlib.h>

int timeCounter;

// DFS function
void dfs(int u, int parent, int** graph, int* size,
         int* disc, int* low, int n) {

    disc[u] = low[u] = ++timeCounter;

    for (int i = 0; i < size[u]; i++) {
        int v = graph[u][i];

        if (v == parent) continue;

        if (disc[v] == -1) {
            dfs(v, u, graph, size, disc, low, n);

            if (low[v] < low[u])
                low[u] = low[v];

            // Bridge condition
            if (low[v] > disc[u]) {
                printf("Bridge: [%d, %d]\n", u, v);
            }
        } else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}

int main() {
    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    // Allocate adjacency list
    int** graph = (int**)malloc(n * sizeof(int*));
    int* size = (int*)calloc(n, sizeof(int));

    // Temporary degree count
    int* degree = (int*)calloc(n, sizeof(int));

    // Read edges first to count degrees
    int (*edges)[2] = malloc(m * sizeof *edges);

    for (int i = 0; i < m; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    // Allocate graph
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(degree[i] * sizeof(int));
    }

    // Fill adjacency list
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u][size[u]++] = v;
        graph[v][size[v]++] = u;
    }

    int* disc = (int*)malloc(n * sizeof(int));
    int* low  = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        disc[i] = -1;
    }

    timeCounter = 0;

    // Handle disconnected graph also
    for (int i = 0; i < n; i++) {
        if (disc[i] == -1) {
            dfs(i, -1, graph, size, disc, low, n);
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    free(size);
    free(degree);
    free(edges);
    free(disc);
    free(low);

    return 0;
}