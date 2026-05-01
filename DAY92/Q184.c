/*
Problem Statement:
Find kth largest element without sorting.

Approach:
- Quickselect Algorithm
*/

#include <stdio.h>

// Swap
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition
int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[right]);
    return i;
}

// Quickselect
int quickSelect(int arr[], int left, int right, int k) {
    if (left == right) return arr[left];

    int pi = partition(arr, left, right);

    if (pi == k) return arr[pi];
    else if (pi < k) return quickSelect(arr, pi + 1, right, k);
    else return quickSelect(arr, left, pi - 1, k);
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    int result = quickSelect(arr, 0, n - 1, n - k);

    printf("%dth largest element: %d\n", k, result);

    return 0;
}