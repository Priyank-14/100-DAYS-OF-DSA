/*
Problem Statement:
Given points on a 2D plane, connect all points with minimum cost such that
there is exactly one simple path between any two points.
Cost = Manhattan Distance.
Return minimum total cost using Prim's Algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

int main() {
    int n;

    printf("Enter number of points: ");
    scanf("%d", &n);

    int points[MAX][2];

    for (int i = 0; i < n; i++) {
        printf("Enter x and y coordinates: ");
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    int minDist[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        minDist[i] = INT_MAX;
    }

    minDist[0] = 0;
    int totalCost = 0;

    // Prim's Algorithm
    for (int i = 0; i < n; i++) {
        int u = -1, minVal = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && minDist[j] < minVal) {
                minVal = minDist[j];
                u = j;
            }
        }

        visited[u] = 1;
        totalCost += minVal;

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) +
                           abs(points[u][1] - points[v][1]);

                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }

    printf("Minimum Cost to Connect All Points: %d\n", totalCost);

    return 0;
}