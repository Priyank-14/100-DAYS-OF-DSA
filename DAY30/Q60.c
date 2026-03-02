/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

ListNode* reverse(ListNode* head) {
    ListNode *prev = NULL, *next = NULL;
    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    int carry = 0;
    ListNode* result = NULL;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        ListNode* newNode = createNode(sum % 10);
        newNode->next = result;
        result = newNode;
    }

    return result;
}

void printList(ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n1, n2, value;
    ListNode *l1 = NULL, *l2 = NULL, *temp;

    printf("Enter number of digits in first number: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        printf("Enter digit: ");
        scanf("%d", &value);

        if (l1 == NULL) {
            l1 = createNode(value);
            temp = l1;
        } else {
            temp->next = createNode(value);
            temp = temp->next;
        }
    }

    printf("Enter number of digits in second number: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        printf("Enter digit: ");
        scanf("%d", &value);

        if (l2 == NULL) {
            l2 = createNode(value);
            temp = l2;
        } else {
            temp->next = createNode(value);
            temp = temp->next;
        }
    }

    ListNode* result = addTwoNumbers(l1, l2);

    printf("Result: ");
    printList(result);

    return 0;
}