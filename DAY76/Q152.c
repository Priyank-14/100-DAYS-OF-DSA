/*
Problem Statement:
Clone an undirected graph using DFS (Deep Copy).
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node* visited[MAX];

// DFS clone
struct Node* dfs(struct Node* node) {
    if (visited[node->val] != NULL) {
        return visited[node->val];
    }

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));

    visited[node->val] = clone;

    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i]);
    }

    return clone;
}

// Helper to create node
struct Node* createNode(int val, int numNeighbors) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->numNeighbors = numNeighbors;
    node->neighbors = (struct Node**)malloc(numNeighbors * sizeof(struct Node*));
    return node;
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* nodes[MAX];

    // Create nodes
    for (int i = 1; i <= n; i++) {
        int k;
        printf("Enter number of neighbors for node %d: ", i);
        scanf("%d", &k);

        nodes[i] = createNode(i, k);

        printf("Enter neighbors:\n");
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            nodes[i]->neighbors[j] = (struct Node*)(long)x; // temp store index
        }
    }

    // Fix pointers
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < nodes[i]->numNeighbors; j++) {
            int idx = (int)(long)nodes[i]->neighbors[j];
            nodes[i]->neighbors[j] = nodes[idx];
        }
    }

    // Initialize visited
    for (int i = 0; i < MAX; i++) {
        visited[i] = NULL;
    }

    struct Node* cloned = dfs(nodes[1]);

    printf("Graph cloned successfully. Starting node: %d\n", cloned->val);

    return 0;
}