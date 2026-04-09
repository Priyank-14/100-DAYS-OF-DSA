/*
Problem:
Implement topological sorting using in-degree array and queue (Kahn’s Algorithm).

Input:
- V (vertices)
- E (edges)
- edges (u v)

Output:
- Topological order OR message if cycle exists
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    // adjacency list
    int* adj[V];
    int size[V];
    int indegree[V];

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(sizeof(int) * E);
        size[i] = 0;
        indegree[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v; // directed edge
        indegree[v]++;
    }

    // queue
    int queue[V];
    int front = 0, rear = 0;

    // push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int topo[V];
    int count = 0;

    // BFS
    while (front < rear) {
        int node = queue[front++];
        topo[count++] = node;

        for (int i = 0; i < size[node]; i++) {
            int next = adj[node][i];
            indegree[next]--;

            if (indegree[next] == 0)
                queue[rear++] = next;
        }
    }

    // check for cycle
    if (count != V) {
        printf("Cycle exists! Topological sort not possible.\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < V; i++) {
            printf("%d ", topo[i]);
        }
    }

    return 0;
}