/*
Problem Statement:
Given a weighted graph with n vertices, compute shortest distances
between every pair of vertices using Floyd-Warshall algorithm.

Input:
- n (number of vertices)
- n x n adjacency matrix
  (-1 indicates no direct edge)

Output:
- Shortest distance matrix
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 1000000000  // large value to represent infinity

int main() {
    int n;
    int dist[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (-1 for no edge):\n");

    // Input and initialization
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &x);

            if (x == -1 && i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = x;
        }
    }

    // Floyd-Warshall Algorithm
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

    // Output result
    printf("Shortest distance matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}