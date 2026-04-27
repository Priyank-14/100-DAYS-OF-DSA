/*
Problem Statement:
Find floor of square root of a non-negative integer x.

Approach:
- Binary Search
- Avoid overflow using division check

Time Complexity: O(log n)
*/

#include <stdio.h>

int main() {
    int x;

    printf("Enter a non-negative integer: ");
    scanf("%d", &x);

    if (x < 2) {
        printf("Square root: %d\n", x);
        return 0;
    }

    int left = 1, right = x / 2;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= x / mid) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("Square root (floor): %d\n", ans);

    return 0;
}