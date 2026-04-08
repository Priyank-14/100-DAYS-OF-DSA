/*
Problem:
Course Schedule II (Topological Sort using BFS)

Input:
- number of courses
- number of prerequisites
- pairs (a b)

Output:
- valid course order OR empty
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Enter number of courses: ");
    scanf("%d", &n);

    printf("Enter number of prerequisites: ");
    scanf("%d", &m);

    int* adj[n];
    int size[n];
    int indegree[n];

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(sizeof(int) * m);
        size[i] = 0;
        indegree[i] = 0;
    }

    printf("Enter prerequisites (a b):\n");
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        adj[b][size[b]++] = a;
        indegree[a]++;
    }

    int queue[n];
    int front = 0, rear = 0;

    // push indegree 0 nodes
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    int result[n];
    int count = 0;

    // BFS
    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;

        for (int i = 0; i < size[node]; i++) {
            int next = adj[node][i];
            indegree[next]--;

            if (indegree[next] == 0)
                queue[rear++] = next;
        }
    }

    if (count != n) {
        printf("No valid ordering (cycle exists)\n");
    } else {
        printf("Course Order:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
    }

    return 0;
}