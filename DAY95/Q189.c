/*
Problem Statement:
Given n real numbers in range [0,1), sort them using Bucket Sort.

Approach:
1. Create n buckets
2. Distribute elements into buckets using index = value * n
3. Sort each bucket (using insertion sort)
4. Concatenate all buckets

Time Complexity:
- Average: O(n)
- Worst: O(n^2) (if all elements fall into one bucket)
*/

#include <stdio.h>
#include <stdlib.h>

// Node for linked list bucket
struct Node {
    float data;
    struct Node* next;
};

// Insert node in sorted order (Insertion Sort in bucket)
struct Node* insertSorted(struct Node* head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at beginning
    if (!head || value < head->data) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next && temp->next->data <= value) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter %d numbers in range [0,1):\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%f", &arr[i]);
    }

    // Step 1: Create buckets
    struct Node* buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        buckets[index] = insertSorted(buckets[index], arr[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];
        while (temp) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.3f ", arr[i]);
    }
    printf("\n");

    return 0;
}