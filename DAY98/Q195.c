/*
Problem Statement:
Given a set of intervals, merge all overlapping intervals.

Approach:
1. Sort intervals by start time
2. Traverse and merge overlapping intervals

Time Complexity: O(n log n)
*/

#include <stdio.h>
#include <stdlib.h>

// Interval structure
typedef struct {
    int start, end;
} Interval;

// Comparator for sorting by start time
int compare(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval arr[n];

    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) {
        printf("Interval %d start: ", i + 1);
        scanf("%d", &arr[i].start);
        printf("Interval %d end: ", i + 1);
        scanf("%d", &arr[i].end);
    }

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    Interval result[n];
    int idx = 0;

    result[idx] = arr[0];

    // Step 2: Merge intervals
    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[idx].end) {
            // Overlapping → merge
            if (arr[i].end > result[idx].end)
                result[idx].end = arr[i].end;
        } else {
            // Non-overlapping → new interval
            idx++;
            result[idx] = arr[i];
        }
    }

    printf("Merged intervals:\n");
    for (int i = 0; i <= idx; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }
    printf("\n");

    return 0;
}