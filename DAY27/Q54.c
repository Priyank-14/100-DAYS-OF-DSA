/*
Given the head of a singly linked list, the task is to remove a cycle if present. A cycle exists when a node's next pointer points back to a previous node, forming a loop. Internally, a variable pos denotes the index of the node where the cycle starts, but it is not passed as a parameter. The terminal will print true if a cycle is removed otherwise, it will print false.

Example 1:
Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like.A loop is present in the list, and it is removed.

Example 2:
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: 
The Linked list does not contains any loop

Example 3:
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like 

A loop is present in the list, and it is removed.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int removeLoop(struct Node* head) {
    
    if(head == NULL || head->next == NULL)
        return 0;
    
    struct Node *slow = head;
    struct Node *fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
            break;
    }
    
    if(fast == NULL || fast->next == NULL)
        return 0;
    
    slow = head;
    
    if(slow == fast) {
        while(fast->next != slow)
            fast = fast->next;
    }
    else {
        while(slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    fast->next = NULL;
    return 1;
}

void printList(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    
    int n, value, pos;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter elements:\n");
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        
        newNode = createNode(value);
        
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    printf("Enter position to create loop (-1 for no loop): ");
    scanf("%d", &pos);
    
    if(pos != -1) {
        struct Node* loopNode = head;
        for(int i = 0; i < pos; i++) {
            loopNode = loopNode->next;
        }
        temp->next = loopNode;
    }
    
    int result = removeLoop(head);
    
    if(result)
        printf("true\n");
    else
        printf("false\n");
    
    printf("Linked List after removal:\n");
    printList(head);
    
    return 0;
}

