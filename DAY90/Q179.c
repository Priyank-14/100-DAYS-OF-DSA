/*
Problem Statement:
Given n boards and k painters, each painter paints contiguous boards.
Each unit length takes 1 unit time.

Find the minimum time required to paint all boards.

Approach:
- Binary Search on answer (maximum time)
- Greedy feasibility check

Time Complexity: O(n log(sum))
*/

#include <stdio.h>

// Check if painting is possible within given maxTime
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (currentTime + boards[i] <= maxTime) {
            currentTime += boards[i];
        } else {
            painters++;
            currentTime = boards[i];

            if (painters > k)
                return 0;
        }
    }

    return 1;
}

int main() {
    int n, k;

    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int boards[n];
    int sum = 0, maxBoard = 0;

    printf("Enter board lengths:\n");
    for (int i = 0; i < n; i++) {
        printf("Board %d: ", i + 1);
        scanf("%d", &boards[i]);

        sum += boards[i];
        if (boards[i] > maxBoard)
            maxBoard = boards[i];
    }

    int left = maxBoard;
    int right = sum;
    int ans = sum;

    // Binary Search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            right = mid - 1;  // try smaller time
        } else {
            left = mid + 1;
        }
    }

    printf("Minimum time required: %d\n", ans);

    return 0;
}