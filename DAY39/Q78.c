/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int num;
    int freq;
} Pair;

int compare(const void *a, const void *b)
{
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    return p2->freq - p1->freq;
}

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &nums[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    Pair arr[n];
    int unique = 0;

    for (int i = 0; i < n; i++)
    {
        int found = 0;

        for (int j = 0; j < unique; j++)
        {
            if (arr[j].num == nums[i])
            {
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            arr[unique].num = nums[i];
            arr[unique].freq = 1;
            unique++;
        }
    }

    qsort(arr, unique, sizeof(Pair), compare);

    printf("Top %d frequent elements are:\n", k);

    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr[i].num);
    }

    return 0;
}