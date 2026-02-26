/*Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* head = NULL;
int size = 0;

/* Create Node */
node* createNode(int val) {
    node* nn = (node*)malloc(sizeof(node));
    nn->data = val;
    nn->next = NULL;
    return nn;
}

/* Get value at index */
int get(int index) {
    if (index < 0 || index >= size) {
        return -1;
    }

    node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

/* Add at head */
void addAtHead(int val) {
    node* nn = createNode(val);
    nn->next = head;
    head = nn;
    size++;
}

/* Add at tail */
void addAtTail(int val) {
    node* nn = createNode(val);

    if (head == NULL) {
        head = nn;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }
    size++;
}

/* Add at index */
void addAtIndex(int index, int val) {
    if (index < 0 || index > size) {
        printf("Invalid index\n");
        return;
    }

    if (index == 0) {
        addAtHead(val);
        return;
    }

    node* nn = createNode(val);
    node* temp = head;

    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    nn->next = temp->next;
    temp->next = nn;
    size++;
}

/* Delete at index */
void deleteAtIndex(int index) {
    if (index < 0 || index >= size) {
        printf("Invalid index\n");
        return;
    }

    node* temp = head;

    if (index == 0) {
        head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        node* delNode = temp->next;
        temp->next = delNode->next;
        free(delNode);
    }
    size--;
}

/* Display list */
void display() {
    node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Free memory */
void freeList() {
    node* temp = head;
    while (temp != NULL) {
        node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}

int main() {
    int choice, val, index;

    while (1) {
        printf("\n1.Add at Head\n2.Add at Tail\n3.Add at Index\n4.Get\n5.Delete at Index\n6.Display\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                addAtHead(val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                addAtTail(val);
                break;

            case 3:
                printf("Enter index and value: ");
                scanf("%d %d", &index, &val);
                addAtIndex(index, val);
                break;

            case 4:
                printf("Enter index: ");
                scanf("%d", &index);
                printf("Value: %d\n", get(index));
                break;

            case 5:
                printf("Enter index: ");
                scanf("%d", &index);
                deleteAtIndex(index);
                break;

            case 6:
                display();
                break;

            case 7:
                freeList();
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


