/*
Problem Statement:
Return count of smaller elements to the right for each element.

Approach:
- Modified Merge Sort
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[], Pair temp[]) {
    int i = left, j = mid + 1, k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

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

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count, temp);

    printf("Counts:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    return 0;
}