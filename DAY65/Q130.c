/*
Problem:
Detect cycle in undirected graph using Union-Find (DSU)

Input:
- V (vertices)
- E (edges)
- edges (u v)

Output:
- YES (cycle exists) or NO (no cycle)
*/

#include <stdio.h>

// Find with path compression
int find(int parent[], int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

// Union function
int unionSet(int parent[], int u, int v) {
    int pu = find(parent, u);
    int pv = find(parent, v);

    if (pu == pv)
        return 1; // cycle found

    parent[pu] = pv;
    return 0;
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    int edges[E][2];

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
    }

    int parent[V];

    // Initialize parent array
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int hasCycle = 0;

    // Process edges
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (unionSet(parent, u, v)) {
            hasCycle = 1;
            break;
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}