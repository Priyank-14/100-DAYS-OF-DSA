/*
Problem Statement:
Given an array of integers containing both positive and negative values,
find the length of the longest contiguous subarray whose sum is equal to zero.
*/

#include <stdio.h>

#define MAX 1000

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[MAX];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxLen = 0;

    // Brute force approach
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == 0) {
                int len = j - i + 1;
                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }
    }

    printf("Length of longest subarray with sum 0: %d\n", maxLen);

    return 0;
}