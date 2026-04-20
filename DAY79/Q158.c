/*
Problem Statement:
Find the number of Strongly Connected Components (SCC)
in a directed graph using Kosaraju’s Algorithm.

Steps:
1. DFS and store nodes in stack (finish time order)
2. Reverse the graph
3. DFS using stack order → count SCCs
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int V, E;
int adj[MAX][MAX], transpose[MAX][MAX];
int visited[MAX];
int stack[MAX], top = -1;

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// First DFS
void dfs1(int u) {
    visited[u] = 1;
    for (int v = 0; v < V; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs1(v);
        }
    }
    push(u);
}

// Second DFS (on transpose)
void dfs2(int u) {
    visited[u] = 1;
    for (int v = 0; v < V; v++) {
        if (transpose[u][v] && !visited[v]) {
            dfs2(v);
        }
    }
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize matrices
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
            transpose[i][j] = 0;
        }
    }

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    // Step 1: DFS and fill stack
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    // Step 2: Transpose graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j]) {
                transpose[j][i] = 1;
            }
        }
    }

    // Reset visited
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    // Step 3: Process stack
    int scc = 0;

    while (top != -1) {
        int node = pop();
        if (!visited[node]) {
            dfs2(node);
            scc++;
        }
    }

    printf("Number of Strongly Connected Components: %d\n", scc);

    return 0;
}