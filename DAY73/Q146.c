/*
Problem Statement:
Given a graph that was originally a tree with one extra edge added,
find the edge that can be removed so the graph becomes a tree again.
If multiple answers exist, return the one that appears last.
*/

#include <stdio.h>
#include <stdlib.h>

// Find with path compression
int find(int* parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

// Union operation
int unionSet(int* parent, int a, int b) {
    int pa = find(parent, a);
    int pb = find(parent, b);

    if (pa == pb) return 0; // cycle found

    parent[pa] = pb;
    return 1;
}

int main() {
    int n;

    printf("Enter number of edges: ");
    scanf("%d", &n);

    int** edges = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        edges[i] = (int*)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    // Dynamic parent array
    int* parent = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int res_u = -1, res_v = -1;

    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (!unionSet(parent, u, v)) {
            res_u = u;
            res_v = v; // keep last occurring cycle edge
        }
    }

    printf("Redundant edge: [%d, %d]\n", res_u, res_v);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(edges[i]);
    }
    free(edges);
    free(parent);

    return 0;
}