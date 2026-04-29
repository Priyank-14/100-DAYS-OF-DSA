/*
Problem Statement:
Place m balls in baskets such that minimum magnetic force
(distance) between any two balls is maximized.

Approach:
- Sort positions
- Binary Search on answer
*/

#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check feasibility
int canPlace(int pos[], int n, int m, int dist) {
    int count = 1;
    int last = pos[0];

    for (int i = 1; i < n; i++) {
        if (pos[i] - last >= dist) {
            count++;
            last = pos[i];
        }
        if (count >= m)
            return 1;
    }
    return 0;
}

int main() {
    int n, m;

    printf("Enter number of baskets: ");
    scanf("%d", &n);

    int pos[n];

    printf("Enter basket positions:\n");
    for (int i = 0; i < n; i++) {
        printf("Position %d: ", i + 1);
        scanf("%d", &pos[i]);
    }

    printf("Enter number of balls: ");
    scanf("%d", &m);

    // Sort positions
    qsort(pos, n, sizeof(int), compare);

    int left = 1;
    int right = pos[n - 1] - pos[0];
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlace(pos, n, m, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("Maximum minimum magnetic force: %d\n", ans);

    return 0;
}