/*
Problem Statement:
Find minimum eating speed k such that all bananas are eaten within h hours.

Approach:
- Binary Search on answer
*/

#include <stdio.h>

long long canEat(int piles[], int n, int h, int k) {
    long long hours = 0;

    for (int i = 0; i < n; i++) {
        hours += (piles[i] + k - 1) / k;  // ceil division
    }

    return hours <= h;
}

int main() {
    int n, h;

    printf("Enter number of piles: ");
    scanf("%d", &n);

    int piles[n];

    printf("Enter bananas in each pile:\n");
    for (int i = 0; i < n; i++) {
        printf("Pile %d: ", i + 1);
        scanf("%d", &piles[i]);
    }

    printf("Enter number of hours: ");
    scanf("%d", &h);

    int left = 1, right = 0;

    // Find max pile
    for (int i = 0; i < n; i++) {
        if (piles[i] > right)
            right = piles[i];
    }

    int ans = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canEat(piles, n, h, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("Minimum eating speed: %d\n", ans);

    return 0;
}