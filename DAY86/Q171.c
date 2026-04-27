/*
Problem Statement:
Find the integer square root of a non-negative integer n.
(The greatest integer x such that x*x <= n)

Approach:
- Binary Search on range [0, n]
- Avoid overflow by using long long for multiplication

Time Complexity: O(log n)
*/

#include <stdio.h>

int main() {
    long long n;

    printf("Enter a non-negative integer: ");
    scanf("%lld", &n);

    long long left = 0, right = n;
    long long ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid * mid <= n) {
            ans = mid;          // possible answer
            left = mid + 1;     // try for bigger
        } else {
            right = mid - 1;
        }
    }

    printf("Integer square root: %lld\n", ans);

    return 0;
}