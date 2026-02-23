/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} node;

node* createNode(int value) {
    node* nn = (node*)malloc(sizeof(node));
    nn->val = value;
    nn->next = NULL;
    return nn;
}

node* insertAtEnd(node* head, int value) {
    node* nn = createNode(value);

    if (head == NULL)
        return nn;

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = nn;
    return head;
}

bool hasCycle(node *head) {
    if (head == NULL || head->next == NULL)
        return false;

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

void createCycle(node* head, int pos) {
    if (pos < 0) return;

    node* temp = head;
    node* cycleNode = NULL;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos)
            cycleNode = temp;
        temp = temp->next;
        index++;
    }

    if (cycleNode != NULL)
        temp->next = cycleNode;
}

int main() {
    int n, value, pos;
    node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    createCycle(head, pos);

    if (hasCycle(head))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}

