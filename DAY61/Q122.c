/*
Problem:
Find number of provinces (connected components) from adjacency matrix.

Input:
- n (number of cities)
- n x n matrix

Output:
- Number of provinces
*/

#include <stdio.h>

// DFS function
void dfs(int n, int isConnected[n][n], int city, int visited[]) {
    visited[city] = 1;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(n, isConnected, i, visited);
        }
    }
}

int main() {
    int n;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    int isConnected[n][n];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(n, isConnected, i, visited);
            provinces++;
        }
    }

    printf("Number of provinces: %d\n", provinces);

    return 0;
}