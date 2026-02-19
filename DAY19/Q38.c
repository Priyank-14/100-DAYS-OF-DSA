/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.*/

#include <stdio.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0;
    int currMax = 0, maxSum = nums[0];
    int currMin = 0, minSum = nums[0];

    for(int i = 0; i < numsSize; i++) {
        total += nums[i];

        currMax = currMax > 0 ? currMax + nums[i] : nums[i];
        if(currMax > maxSum)
            maxSum = currMax;

        currMin = currMin < 0 ? currMin + nums[i] : nums[i];
        if(currMin < minSum)
            minSum = currMin;
    }

    if(maxSum < 0)
        return maxSum;

    int circularSum = total - minSum;
    return maxSum > circularSum ? maxSum : circularSum;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int result = maxSubarraySumCircular(nums, n);

    printf("Maximum Circular Subarray Sum: %d\n", result);

    return 0;
}
