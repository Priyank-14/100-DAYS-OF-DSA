/*
Problem:
Using DFS and parent tracking, detect if an undirected graph has a cycle.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- YES (cycle exists) or NO (no cycle)
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

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    struct Node* newNode2 = createNode(src);
    newNode2->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode2;
}

// DFS to detect cycle
int dfs(struct Graph* graph, int vertex, int visited[], int parent) {
    visited[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];

    while (temp) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            if (dfs(graph, adjVertex, visited, vertex))
                return 1;
        }
        else if (adjVertex != parent) {
            return 1; // cycle detected
        }

        temp = temp->next;
    }

    return 0;
}

// Function to check cycle in graph
int hasCycle(struct Graph* graph) {
    int visited[graph->numVertices];

    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = 0;

    // Check for all components
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, -1))
                return 1;
        }
    }

    return 0;
}

// Main
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

    if (hasCycle(graph))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}