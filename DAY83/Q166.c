/*
Problem Statement:
Search target in a rotated sorted array using O(log n).

Approach:
- Modified Binary Search
*/

#include <stdio.h>

int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter rotated sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    int left = 0, right = n - 1;
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            ans = mid;
            break;
        }

        // Left half sorted
        if (arr[left] <= arr[mid]) {
            if (arr[left] <= target && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // Right half sorted
        else {
            if (arr[mid] < target && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    if (ans != -1)
        printf("Target found at index: %d\n", ans);
    else
        printf("Target not found (-1)\n");

    return 0;
}