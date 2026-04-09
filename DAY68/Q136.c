/*
Problem:
Alien Dictionary using Topological Sort (Kahn's Algorithm)

Input:
- n (number of words)
- words

Output:
- valid character order OR empty string
*/

#include <stdio.h>
#include <string.h>

#define MAX 26

int main() {
    int n;

    printf("Enter number of words: ");
    scanf("%d", &n);

    char words[n][101];

    printf("Enter words:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int present[MAX] = {0};

    // mark present characters
    for (int i = 0; i < n; i++) {
        for (int j = 0; words[i][j]; j++) {
            present[words[i][j] - 'a'] = 1;
        }
    }

    // build graph
    for (int i = 0; i < n - 1; i++) {
        char *s1 = words[i];
        char *s2 = words[i + 1];

        int len = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);
        int found = 0;

        for (int j = 0; j < len; j++) {
            if (s1[j] != s2[j]) {
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';

                if (!adj[u][v]) {
                    adj[u][v] = 1;
                    indegree[v]++;
                }
                found = 1;
                break;
            }
        }

        // invalid case: prefix issue
        if (!found && strlen(s1) > strlen(s2)) {
            printf("Invalid dictionary (no order possible)\n");
            return 0;
        }
    }

    // queue
    int queue[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < MAX; i++) {
        if (present[i] && indegree[i] == 0)
            queue[rear++] = i;
    }

    char result[27];
    int idx = 0;

    // BFS (Kahn's Algorithm)
    while (front < rear) {
        int node = queue[front++];
        result[idx++] = node + 'a';

        for (int i = 0; i < MAX; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    result[idx] = '\0';

    // count total characters
    int total = 0;
    for (int i = 0; i < MAX; i++)
        if (present[i]) total++;

    if (idx != total) {
        printf("Invalid dictionary (cycle detected)\n");
    } else {
        printf("Alien Order: %s\n", result);
    }

    return 0;
}