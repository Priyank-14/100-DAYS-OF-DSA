/*
Problem Statement:
Given n stalls and k cows, place the cows such that the minimum
distance between any two cows is maximized.

Approach:
- Sort stall positions
- Binary Search on answer (distance)
- Check feasibility using greedy placement

Time Complexity: O(n log n + n log(maxDist))
*/

#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place k cows with at least 'dist' spacing
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;  // first cow at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }
        if (count >= k)
            return 1;
    }

    return 0;
}

int main() {
    int n, k;

    printf("Enter number of stalls and cows: ");
    scanf("%d %d", &n, &k);

    int stalls[n];

    printf("Enter stall positions:\n");
    for (int i = 0; i < n; i++) {
        printf("Position %d: ", i + 1);
        scanf("%d", &stalls[i]);
    }

    // Step 1: Sort stalls
    qsort(stalls, n, sizeof(int), compare);

    int left = 1;
    int right = stalls[n - 1] - stalls[0];
    int ans = 0;

    // Binary Search on distance
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;
            left = mid + 1;   // try bigger distance
        } else {
            right = mid - 1;
        }
    }

    printf("Maximum minimum distance: %d\n", ans);

    return 0;
}