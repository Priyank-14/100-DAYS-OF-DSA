/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 */

#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int n) {
    int* answer = (int*)malloc(n * sizeof(int));

    int prefix = 1;
    for (int i = 0; i < n; i++) {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &nums[i]);
    }

    int* result = productExceptSelf(nums, n);

    printf("Product array except self:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    free(nums);
    free(result);
    return 0;
}
