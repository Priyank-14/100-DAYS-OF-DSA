/*
Problem Statement:
Given a sorted array, return index of target if found,
otherwise return the index where it should be inserted.

Time Complexity: O(log n)
*/

#include <stdio.h>

int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    int left = 0, right = n - 1;
    int ans = n;  // default insertion position

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("Index: %d\n", ans);

    return 0;
}