/*
Problem Statement:
For each element in an array, count how many smaller elements appear to its right.

Approach:
- Use modified Merge Sort
- Track original indices
- During merge, count how many right-side elements move before left elements

Time Complexity: O(n log n)
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to store value and original index
typedef struct {
    int val;
    int index;
} Pair;

// Merge step with counting
void merge(Pair arr[], int left, int mid, int right, int count[], Pair temp[]) {
    int i = left, j = mid + 1, k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;  // smaller element from right
        } else {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

// Merge sort
void mergeSort(Pair arr[], int left, int right, int count[], Pair temp[]) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, count, temp);
    mergeSort(arr, mid + 1, right, count, temp);

    merge(arr, left, mid, right, count, temp);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    Pair arr[n], temp[n];
    int count[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count, temp);

    printf("Count of smaller elements on right:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    return 0;
}