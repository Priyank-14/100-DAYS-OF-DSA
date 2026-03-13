/*Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if(rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if(front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued element: %d\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char op[10];

        printf("Enter operation (enqueue/dequeue): ");
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0) {
            int x;
            printf("Enter value to enqueue: ");
            scanf("%d", &x);
            enqueue(x);
        }
        else if(strcmp(op, "dequeue") == 0) {
            dequeue();
        }
        else {
            printf("Invalid operation\n");
        }
    }

    return 0;
}