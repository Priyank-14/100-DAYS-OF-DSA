/*
Problem Statement:
Find a peak element in an array using O(log n) time.

A peak element is greater than its neighbors.
*/

#include <stdio.h>

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

    int left = 0, right = n - 1;

    // Binary Search
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    printf("Peak element found at index: %d\n", left);
    printf("Peak element value: %d\n", arr[left]);

    return 0;
}