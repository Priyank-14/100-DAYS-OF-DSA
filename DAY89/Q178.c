/*
Problem Statement:
Find minimum ship capacity to ship all packages within given days.

Approach:
- Binary Search on answer
*/

#include <stdio.h>

// Check feasibility
int canShip(int weights[], int n, int days, int capacity) {
    int d = 1;
    int current = 0;

    for (int i = 0; i < n; i++) {
        if (current + weights[i] <= capacity) {
            current += weights[i];
        } else {
            d++;
            current = weights[i];
        }
    }

    return d <= days;
}

int main() {
    int n, days;

    printf("Enter number of packages: ");
    scanf("%d", &n);

    int weights[n];

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++) {
        printf("Package %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    printf("Enter number of days: ");
    scanf("%d", &days);

    int left = 0, right = 0;

    // Initialize bounds
    for (int i = 0; i < n; i++) {
        if (weights[i] > left)
            left = weights[i];
        right += weights[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canShip(weights, n, days, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("Minimum ship capacity: %d\n", ans);

    return 0;
}