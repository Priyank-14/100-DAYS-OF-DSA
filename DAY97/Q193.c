/*
Problem Statement:
Given meeting intervals, find minimum number of meeting rooms required.

Approach:
1. Sort intervals by start time
2. Use min-heap to track earliest ending meeting
3. If next meeting starts after earliest end → reuse room
4. Else → allocate new room

Time Complexity: O(n log n)
*/

#include <stdio.h>
#include <stdlib.h>

// Interval structure
typedef struct {
    int start, end;
} Interval;

// Sort by start time
int compare(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

// Swap
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Min heapify
void heapify(int heap[], int size, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

// Insert into heap
void push(int heap[], int* size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Replace root
void popAndPush(int heap[], int size, int val) {
    heap[0] = val;
    heapify(heap, size, 0);
}

int main() {
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    Interval arr[n];

    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        printf("Meeting %d start: ", i + 1);
        scanf("%d", &arr[i].start);
        printf("Meeting %d end: ", i + 1);
        scanf("%d", &arr[i].end);
    }

    // Step 1: Sort by start time
    qsort(arr, n, sizeof(Interval), compare);

    int heap[n];
    int size = 0;

    // First meeting
    push(heap, &size, arr[0].end);

    // Process meetings
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= heap[0]) {
            // reuse room
            popAndPush(heap, size, arr[i].end);
        } else {
            // need new room
            push(heap, &size, arr[i].end);
        }
    }

    printf("Minimum rooms required: %d\n", size);

    return 0;
}