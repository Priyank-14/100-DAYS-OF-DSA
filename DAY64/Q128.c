/*
Problem:
Rotting Oranges using BFS

Input:
- rows, cols
- grid

Output:
- minimum minutes or -1
*/

#include <stdio.h>

// Structure for queue
struct Node {
    int r, c;
};

int main() {
    int m, n;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int grid[10][10];

    printf("Enter grid:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    struct Node queue[100];
    int front = 0, rear = 0;

    int fresh = 0;

    // Initialize queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (struct Node){i, j};
            }
            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int minutes = 0;

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    // BFS
    while (front < rear && fresh > 0) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node curr = queue[front++];

            for (int k = 0; k < 4; k++) {
                int nr = curr.r + dr[k];
                int nc = curr.c + dc[k];

                if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    queue[rear++] = (struct Node){nr, nc};
                }
            }
        }
        minutes++;
    }

    if (fresh > 0)
        printf("-1\n");
    else
        printf("Minimum minutes: %d\n", minutes);

    return 0;
}