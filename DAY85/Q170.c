/*
Problem Statement:
Find the minimum element in a rotated sorted array.

Approach:
- Binary Search
- O(log n)
*/

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter rotated sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    printf("Minimum element: %d\n", arr[left]);

    return 0;
}