/*
Problem Statement:
Given a weighted undirected graph, compute the total weight of its
Minimum Spanning Tree (MST) using Prim’s algorithm.

Input Format:
n m
u v w
...

Output Format:
Total weight of MST.

Sample Input:
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output:
6

Explanation:
One possible MST edges: (2-3), (3-4), (1-2)
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];
int visited[MAX];

int minKey(int key[]) {
    int min = INT_MAX, min_index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST() {
    int key[MAX];
    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start from vertex 1
    key[1] = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key);
        visited[u] = 1;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int result = primMST();
    printf("Total weight of MST: %d\n", result);

    return 0;
}