/*
Problem Statement:
Given an undirected graph, find all articulation points (cut vertices).
A vertex is an articulation point if removing it increases the number
of connected components.

Approach:
- Use DFS (Tarjan’s Algorithm)
- Track discovery time (disc[]) and lowest reachable time (low[])

Time Complexity: O(V + E)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Linked list node
struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];

int visited[MAX], disc[MAX], low[MAX], ap[MAX];
int timeCounter = 0;
int V, E;

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function
void dfs(int u, int parent) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;
    int children = 0;

    struct Node* temp = adj[u];

    while (temp != NULL) {
        int v = temp->data;

        if (!visited[v]) {
            children++;
            dfs(v, u);

            if (low[v] < low[u])
                low[u] = low[v];

            if (parent != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if (v != parent) {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }

        temp = temp->next;
    }

    if (parent == -1 && children > 1)
        ap[u] = 1;
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize
    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        ap[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Run DFS
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    // Output articulation points (sorted automatically)
    printf("Articulation Points: ");
    int found = 0;

    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("-1");

    printf("\n");

    return 0;
}