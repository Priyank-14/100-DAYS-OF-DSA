/*
Problem:
Perform DFS starting from a given source vertex using recursion.

Input:
- n (number of vertices)
- adjacency list
- starting vertex s

Output:
- DFS traversal order
*/

#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge (undirected for simplicity)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph
    struct Node* newNode2 = createNode(src);
    newNode2->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode2;
}

// DFS function
void dfs(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];

    while (temp) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            dfs(graph, adjVertex, visited);
        }

        temp = temp->next;
    }
}

// Main function
int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Graph* graph = createGraph(n);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal:\n");
    dfs(graph, start, visited);

    return 0;
}