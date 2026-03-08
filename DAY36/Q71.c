/*Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.*/


#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node *front = NULL, *rear = NULL;

void enqueue(int x){
    node *nn = (node*)malloc(sizeof(node));
    nn->data = x;

    if(front == NULL){
        front = rear = nn;
        nn->next = front;
    }
    else{
        rear->next = nn;
        rear = nn;
        rear->next = front;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue Underflow\n");
        return;
    }

    node *temp = front;

    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

void display(){
    if(front == NULL){
        printf("Queue is empty");
        return;
    }

    node *temp = front;

    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != front);
}

int main(){
    int n, m, x;

    printf("Enter number of elements to enqueue: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&x);
        enqueue(x);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d",&m);

    for(int i=0;i<m;i++){
        dequeue();
    }

    printf("Queue elements from front to rear:\n");
    display();

    return 0;
}