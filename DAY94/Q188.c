/*
Problem Statement:
Sort arr1 according to arr2 order.
Remaining elements → sorted ascending.

Approach:
- Counting Sort
*/

#include <stdio.h>

int main() {
    int n1, n2;

    printf("Enter size of arr1: ");
    scanf("%d", &n1);

    int arr1[n1];

    printf("Enter elements of arr1:\n");
    for (int i = 0; i < n1; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of arr2: ");
    scanf("%d", &n2);

    int arr2[n2];

    printf("Enter elements of arr2:\n");
    for (int i = 0; i < n2; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    int count[1001] = {0};

    // Count frequency
    for (int i = 0; i < n1; i++) {
        count[arr1[i]]++;
    }

    int result[n1];
    int index = 0;

    // Arrange as per arr2
    for (int i = 0; i < n2; i++) {
        while (count[arr2[i]] > 0) {
            result[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    // Remaining elements sorted
    for (int i = 0; i <= 1000; i++) {
        while (count[i] > 0) {
            result[index++] = i;
            count[i]--;
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}