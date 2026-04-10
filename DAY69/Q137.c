/*
Problem Statement:
Given a weighted graph with non-negative edges, compute the shortest path
from a source vertex to all other vertices using Dijkstra's Algorithm
with a Priority Queue (Min-Heap).
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Structure for graph
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Structure for Min Heap Node
struct MinHeapNode {
    int vertex;
    int dist;
};

// Structure for Min Heap
struct MinHeap {
    int size;
    struct MinHeapNode heap[MAX];
};

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge to graph
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

// Swap heap nodes
void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(struct MinHeap* heap, int idx) {
    while (idx && heap->heap[idx].dist < heap->heap[(idx - 1) / 2].dist) {
        swap(&heap->heap[idx], &heap->heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

// Heapify down
void heapifyDown(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->heap[left].dist < heap->heap[smallest].dist)
        smallest = left;

    if (right < heap->size && heap->heap[right].dist < heap->heap[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->heap[idx], &heap->heap[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Insert into heap
void insertHeap(struct MinHeap* heap, int v, int dist) {
    int i = heap->size++;
    heap->heap[i].vertex = v;
    heap->heap[i].dist = dist;
    heapifyUp(heap, i);
}

// Extract min
struct MinHeapNode extractMin(struct MinHeap* heap) {
    struct MinHeapNode root = heap->heap[0];
    heap->heap[0] = heap->heap[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

// Dijkstra's Algorithm
void dijkstra(struct Graph* graph, int src) {
    int dist[MAX];
    int visited[MAX] = {0};

    struct MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < graph->V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    insertHeap(&heap, src, 0);

    while (heap.size > 0) {
        struct MinHeapNode minNode = extractMin(&heap);
        int u = minNode.vertex;

        if (visited[u]) continue;
        visited[u] = 1;

        struct Node* temp = graph->adj[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("\nShortest distances from source %d:\n", src);
    for (int i = 0; i < graph->V; i++) {
        printf("Vertex %d -> Distance %d\n", i, dist[i]);
    }
}

int main() {
    int V, E, src;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    struct Graph graph;
    graph.V = V;

    for (int i = 0; i < V; i++) {
        graph.adj[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        printf("Enter source, destination and weight: ");
        scanf("%d %d %d", &u, &v, &w);
        addEdge(&graph, u, v, w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(&graph, src);

    return 0;
}