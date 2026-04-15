/*
Problem Statement:
Given an n x n adjacency matrix representing connections between cities,
find the number of provinces (connected components).
*/

#include <stdio.h>

#define MAX 200

int visited[MAX];

// DFS function
void dfs(int city, int n, int isConnected[MAX][MAX]) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(i, n, isConnected);
        }
    }
}

int main() {
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int isConnected[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int provinces = 0;

    // Count connected components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, isConnected);
            provinces++;
        }
    }

    printf("Number of provinces: %d\n", provinces);

    return 0;
}