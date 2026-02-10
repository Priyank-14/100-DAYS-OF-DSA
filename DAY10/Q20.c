/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000*/
#include <stdio.h>
#include <stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int freq[1001] = {0};

    for (int i = 0; i < nums1Size; i++) {
        freq[nums1[i]]++;
    }

    int maxSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* result = (int*)malloc(sizeof(int) * maxSize);

    int k = 0;

    for (int i = 0; i < nums2Size; i++) {
        if (freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }

    *returnSize = k;
    return result;
}

int main() {
    int n1, n2;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    int* nums1 = (int*)malloc(sizeof(int) * n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter nums1[%d]: ", i);
        scanf("%d", &nums1[i]);
    }

    printf("\nEnter size of second array: ");
    scanf("%d", &n2);

    int* nums2 = (int*)malloc(sizeof(int) * n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter nums2[%d]: ", i);
        scanf("%d", &nums2[i]);
    }

    int returnSize = 0;
    int* ans = intersect(nums1, n1, nums2, n2, &returnSize);

    printf("\nIntersection array:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }

    // free memory
    free(nums1);
    free(nums2);
    free(ans);

    return 0;
}
