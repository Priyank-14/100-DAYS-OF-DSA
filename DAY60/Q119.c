/*
Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.
*/

#include <stdio.h>

// Function to check Min-Heap property
int isMinHeap(int arr[], int n) {
    // Check all parent nodes
    for (int i = 0; i <= (n - 2) / 2; i++) {

        // Left child index = 2*i + 1
        if (2 * i + 1 < n && arr[i] > arr[2 * i + 1])
            return 0;

        // Right child index = 2*i + 2
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2])
            return 0;
    }
    return 1;
}

// Main function
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level-order traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isMinHeap(arr, n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}