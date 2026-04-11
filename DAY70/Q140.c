/*
Problem Statement:
Given n cities and flight connections with costs,
find the cheapest price from source to destination with at most k stops.
If not possible, return -1.
*/

#include <stdio.h>
#include <limits.h>

#define MAX 101

int main() {
    int n, m, src, dst, k;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter number of flights: ");
    scanf("%d", &m);

    int flights[MAX][3];

    for (int i = 0; i < m; i++) {
        printf("Enter from, to, price: ");
        scanf("%d %d %d", &flights[i][0], &flights[i][1], &flights[i][2]);
    }

    printf("Enter source city: ");
    scanf("%d", &src);

    printf("Enter destination city: ");
    scanf("%d", &dst);

    printf("Enter maximum stops (k): ");
    scanf("%d", &k);

    int dist[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    // Bellman-Ford for k+1 iterations
    for (int i = 0; i <= k; i++) {
        int temp[MAX];

        for (int j = 0; j < n; j++) {
            temp[j] = dist[j];
        }

        for (int j = 0; j < m; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int w = flights[j][2];

            if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                temp[v] = dist[u] + w;
            }
        }

        for (int j = 0; j < n; j++) {
            dist[j] = temp[j];
        }
    }

    if (dist[dst] == INT_MAX) {
        printf("Output: -1\n");
    } else {
        printf("Output: %d\n", dist[dst]);
    }

    return 0;
}