/*
Problem Statement:
Find shortest distances from a source vertex in a weighted graph
with non-negative weights using Dijkstra’s Algorithm.

Input Format:
n m
u v w
...
source

Output Format:
Distances to all vertices.

Sample Input:
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output:
0 2 3 9 6
*/

#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];

// Get vertex with minimum distance
int minDistance() {
    int min = INT_MAX, min_index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int src) {
    // Initialize distances
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 1; count <= n; count++) {
        int u = minDistance();
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
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
        graph[v][u] = w; // remove this line if graph is directed
    }

    int source;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    printf("Shortest distances from source:\n");
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}