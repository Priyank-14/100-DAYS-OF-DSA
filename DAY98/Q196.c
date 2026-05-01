/*
Problem Statement:
Merge all overlapping intervals.

Approach:
- Sort by start time
- Merge intervals greedily
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void* a, const void* b) {
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

    // Sort intervals
    qsort(arr, n, sizeof(Interval), cmp);

    Interval result[n];
    int idx = 0;

    result[0] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[idx].end) {
            // merge
            if (arr[i].end > result[idx].end)
                result[idx].end = arr[i].end;
        } else {
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