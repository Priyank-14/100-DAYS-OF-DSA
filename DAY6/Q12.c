/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:
Input: nums = [0]
Output: [0]
Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1*/
#include <stdio.h>

void moveZeroes(int nums[], int n)
{
    int i = 0;

    for (int j = 0; j < n; j++)
    {
        if (nums[j] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }
}

int main()
{
    int n;
    printf("Enter size of array:");
    scanf("%d", &n);

    int nums[n];
    printf("Enter elements of array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    moveZeroes(nums, n);
    printf("Array after moving zeroes:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
