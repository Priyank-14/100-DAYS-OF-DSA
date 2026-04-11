/*
Problem Statement:
Given a network of n nodes and directed edges with travel times,
compute the minimum time required for all nodes to receive a signal
from a given source node k using Dijkstra's Algorithm.
If any node is unreachable, return -1.
*/

#include <stdio.h>
#include <limits.h>

#define MAX 101

int main() {
    int n, m, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    int dist[MAX][MAX];

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        printf("Enter source, destination and weight: ");
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = w;
    }

    printf("Enter source node: ");
    scanf("%d", &k);

    int minDist[MAX], visited[MAX] = {0};

    for (int i = 1; i <= n; i++) {
        minDist[i] = INT_MAX;
    }

    minDist[k] = 0;

    // Dijkstra
    for (int i = 1; i <= n; i++) {
        int u = -1, minVal = INT_MAX;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && minDist[j] < minVal) {
                minVal = minDist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && dist[u][v] != INT_MAX &&
                minDist[u] + dist[u][v] < minDist[v]) {
                minDist[v] = minDist[u] + dist[u][v];
            }
        }
    }

    int maxTime = 0;

    for (int i = 1; i <= n; i++) {
        if (minDist[i] == INT_MAX) {
            printf("Output: -1\n");
            return 0;
        }
        if (minDist[i] > maxTime) {
            maxTime = minDist[i];
        }
    }

    printf("Output: %d\n", maxTime);

    return 0;
}