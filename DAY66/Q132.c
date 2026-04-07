/*
Problem:
Course Schedule (Detect cycle in directed graph)

Input:
- number of courses
- number of prerequisites
- pairs (a b)

Output:
- true / false
*/

#include <stdio.h>
#include <stdlib.h>

// DFS
int dfs(int node, int visited[], int recStack[], int* adj[], int size[]) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int next = adj[node][i];

        if (!visited[next]) {
            if (dfs(next, visited, recStack, adj, size))
                return 1;
        }
        else if (recStack[next]) {
            return 1;
        }
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    int n, m;

    printf("Enter number of courses: ");
    scanf("%d", &n);

    printf("Enter number of prerequisites: ");
    scanf("%d", &m);

    int* adj[n];
    int size[n];

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(sizeof(int) * m);
        size[i] = 0;
    }

    printf("Enter prerequisites (a b):\n");
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[b][size[b]++] = a;
    }

    int visited[n], recStack[n];

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    int canFinish = 1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack, adj, size)) {
                canFinish = 0;
                break;
            }
        }
    }

    if (canFinish)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}