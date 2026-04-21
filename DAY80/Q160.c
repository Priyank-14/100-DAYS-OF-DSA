/*
Problem Statement:
Find the city with the smallest number of reachable cities
within a given distance threshold.

If multiple cities → return the city with greatest index.

Approach:
- Floyd-Warshall Algorithm
- Dynamic memory using malloc
*/

#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int main() {
    int n, m, threshold;

    printf("Enter number of cities and edges: ");
    scanf("%d %d", &n, &m);

    // Allocate 2D distance matrix dynamically
    int** dist = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
    }

    // Initialize matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);

        dist[u][v] = w;
        dist[v][u] = w;
    }

    printf("Enter distance threshold: ");
    scanf("%d", &threshold);

    // Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int minCount = INF, city = -1;

    // Count reachable cities
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dist[i][j] <= threshold) {
                count++;
            }
        }

        // Tie-breaking → largest index
        if (count <= minCount) {
            minCount = count;
            city = i;
        }
    }

    printf("City with smallest reachable neighbors: %d\n", city);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(dist[i]);
    }
    free(dist);

    return 0;
}