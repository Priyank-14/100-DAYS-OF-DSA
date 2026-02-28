/*Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* createNode(int value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(ListNode** head, int value) {
    ListNode* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    ListNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

bool isPalindrome(ListNode* head) {

    if (!head || !head->next)
        return true;

    ListNode *slow = head, *fast = head;
    ListNode *prev = NULL, *next = NULL;

    while (fast && fast->next) {
        fast = fast->next->next;

        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    if (fast)
        slow = slow->next;

    while (prev && slow) {
        if (prev->val != slow->val)
            return false;

        prev = prev->next;
        slow = slow->next;
    }

    return true;
}

int main() {

    int n, value;
    ListNode* head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    if (isPalindrome(head))
        printf("Output: true\n");
    else
        printf("Output: false\n");

    return 0;
}