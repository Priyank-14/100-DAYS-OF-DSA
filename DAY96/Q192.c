/*
Problem Statement:
Count reverse pairs such that:
i < j and nums[i] > 2 * nums[j]

Approach:
- Modified Merge Sort + Two Pointers
*/

#include <stdio.h>
#include <stdlib.h>

long long merge(int nums[], int left, int mid, int right) {
    long long count = 0;

    int j = mid + 1;

    // Count reverse pairs
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }

    // Merge step
    int size = right - left + 1;
    int* temp = (int*)malloc(size * sizeof(int));

    int i = left, k = 0;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) temp[k++] = nums[i++];
        else temp[k++] = nums[j++];
    }

    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];

    for (i = 0; i < k; i++) {
        nums[left + i] = temp[i];
    }

    free(temp);
    return count;
}

long long mergeSort(int nums[], int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;

    long long count = 0;

    count += mergeSort(nums, left, mid);
    count += mergeSort(nums, mid + 1, right);
    count += merge(nums, left, mid, right);

    return count;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    long long result = mergeSort(nums, 0, n - 1);

    printf("Number of reverse pairs: %lld\n", result);

    return 0;
}
