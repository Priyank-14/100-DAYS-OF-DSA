/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* insertEnd(struct ListNode* head, int value) {
    struct ListNode* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = createNode(0);
    struct ListNode* current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {

        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        current->next = createNode(sum % 10);
        current = current->next;
    }

    return dummy->next;
}

void printList(struct ListNode* head) {
    printf("Result Linked List: ");
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2, value;
    struct ListNode* l1 = NULL;
    struct ListNode* l2 = NULL;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n1);

    printf("Enter elements of first list (in reverse order): ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        l1 = insertEnd(l1, value);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &n2);

    printf("Enter elements of second list (in reverse order): ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        l2 = insertEnd(l2, value);
    }

    struct ListNode* result = addTwoNumbers(l1, l2);

    printList(result);

    return 0;
}