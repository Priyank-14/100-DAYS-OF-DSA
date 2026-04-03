/*
Problem:
Check if all rooms can be visited using given keys.

Input:
- n (rooms)
- For each room:
    number of keys
    keys list

Output:
- true / false
*/

#include <stdio.h>

// DFS
void dfs(int n, int rooms[n][1000], int sizes[], int room, int visited[]) {
    visited[room] = 1;

    for (int i = 0; i < sizes[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(n, rooms, sizes, key, visited);
        }
    }
}

int main() {
    int n;

    printf("Enter number of rooms: ");
    scanf("%d", &n);

    int rooms[n][1000];   // store keys
    int sizes[n];         // number of keys in each room

    printf("Enter keys for each room:\n");
    for (int i = 0; i < n; i++) {
        printf("Number of keys in room %d: ", i);
        scanf("%d", &sizes[i]);

        printf("Enter keys: ");
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &rooms[i][j]);
        }
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Start DFS from room 0
    dfs(n, rooms, sizes, 0, visited);

    // Check all visited
    int allVisited = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            allVisited = 0;
            break;
        }
    }

    if (allVisited)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}