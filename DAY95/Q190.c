/*
Problem Statement:
Find maximum difference between successive elements in sorted array
in O(n) time using bucket method.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Maximum gap: 0\n");
        return 0;
    }

    int nums[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    int minVal = INT_MAX, maxVal = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    if (minVal == maxVal) {
        printf("Maximum gap: 0\n");
        return 0;
    }

    int gap = (maxVal - minVal + n - 2) / (n - 1);
    int bucketCount = (maxVal - minVal) / gap + 1;

    int* bucketMin = (int*)malloc(bucketCount * sizeof(int));
    int* bucketMax = (int*)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    // Fill buckets
    for (int i = 0; i < n; i++) {
        int idx = (nums[i] - minVal) / gap;

        if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
    }

    int maxGap = 0;
    int prevMax = minVal;

    for (int i = 0; i < bucketCount; i++) {
        if (bucketMin[i] == INT_MAX) continue;

        if (bucketMin[i] - prevMax > maxGap)
            maxGap = bucketMin[i] - prevMax;

        prevMax = bucketMax[i];
    }

    printf("Maximum gap: %d\n", maxGap);

    free(bucketMin);
    free(bucketMax);

    return 0;
}