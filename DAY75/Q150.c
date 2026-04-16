/*
Problem Statement:
Given an undirected graph, determine whether it is bipartite.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    int size[MAX];

    // Input adjacency list
    for (int i = 0; i < n; i++) {
        printf("Enter number of neighbors for node %d: ", i);
        scanf("%d", &size[i]);

        printf("Enter neighbors:\n");
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int color[MAX];
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }

    int queue[MAX];

    for (int i = 0; i < n; i++) {
        
        if (color[i] != -1) continue;

        int front = 0, rear = 0;
        queue[rear++] = i;
        color[i] = 0;

        while (front < rear) {
            int node = queue[front++];

            for (int j = 0; j < size[node]; j++) {
                int neighbor = graph[node][j];

                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                } 
                else if (color[neighbor] == color[node]) {
                    printf("Graph is NOT Bipartite\n");
                    return 0;
                }
            }
        }
    }

    printf("Graph is Bipartite\n");

    return 0;
}