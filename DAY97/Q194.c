/*
Problem Statement:
Given meeting intervals, find minimum number of rooms required.

Approach:
- Sort start and end times separately
- Use two pointers
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int start[n], end[n];

    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        printf("Meeting %d start: ", i + 1);
        scanf("%d", &start[i]);
        printf("Meeting %d end: ", i + 1);
        scanf("%d", &end[i]);
    }

    // Sort both arrays
    qsort(start, n, sizeof(int), cmp);
    qsort(end, n, sizeof(int), cmp);

    int i = 0, j = 0;
    int rooms = 0, maxRooms = 0;

    while (i < n) {
        if (start[i] < end[j]) {
            rooms++;
            if (rooms > maxRooms) maxRooms = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    printf("Minimum rooms required: %d\n", maxRooms);

    return 0;
}