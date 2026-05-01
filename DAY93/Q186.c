/*
Problem Statement:
Sort a singly linked list using insertion sort.

Approach:
- Build sorted list using insertion logic
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int val;
    struct Node* next;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Insert at end (for input)
struct Node* insertEnd(struct Node* head, int val) {
    struct Node* newNode = createNode(val);
    if (!head) return newNode;

    struct Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Insertion Sort on Linked List
struct Node* insertionSort(struct Node* head) {
    struct Node dummy;
    dummy.next = NULL;

    struct Node* curr = head;

    while (curr) {
        struct Node* next = curr->next;

        struct Node* prev = &dummy;

        while (prev->next && prev->next->val < curr->val) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;

        curr = next;
    }

    return dummy.next;
}

// Print list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* head = NULL;

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        int x;
        printf("Node %d: ", i + 1);
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    head = insertionSort(head);

    printf("Sorted linked list:\n");
    printList(head);

    return 0;
}