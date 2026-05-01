/*
Problem Statement:
Count number of inversions in an array.

Definition:
An inversion is a pair (i, j) such that:
i < j and arr[i] > arr[j]

Approach:
- Use modified Merge Sort
- Count inversions during merge step

Time Complexity: O(n log n)
*/

#include <stdio.h>
#include <stdlib.h>

// Merge function with inversion counting
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;     // left subarray
    int j = mid + 1;  // right subarray
    int k = left;
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // all remaining elements in left are greater
        }
    }

    // Copy remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Merge Sort with inversion counting
long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid, right);
    }

    return inv_count;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int* temp = (int*)malloc(n * sizeof(int));

    long long inversions = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions: %lld\n", inversions);

    free(temp);

    return 0;
}