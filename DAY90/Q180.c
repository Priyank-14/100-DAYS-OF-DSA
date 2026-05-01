/*
Problem Statement:
Split array into k subarrays such that the largest sum is minimized.

Approach:
- Binary Search on answer
*/

#include <stdio.h>

// Feasibility check
int canSplit(int nums[], int n, int k, int maxSum) {
    int count = 1;
    int current = 0;

    for (int i = 0; i < n; i++) {
        if (current + nums[i] <= maxSum) {
            current += nums[i];
        } else {
            count++;
            current = nums[i];
        }
    }

    return count <= k;
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    printf("Enter number of subarrays (k): ");
    scanf("%d", &k);

    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > left)
            left = nums[i];
        right += nums[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canSplit(nums, n, k, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("Minimum largest subarray sum: %d\n", ans);

    return 0;
}