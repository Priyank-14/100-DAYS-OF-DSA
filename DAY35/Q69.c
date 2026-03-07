/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Use array and front/rear pointers. Enqueue inserts at rear, dequeue removes from front. Display from front to rear.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void enque(int x){
    node* nn = (node*)malloc(sizeof(node));
    nn->data = x;
    nn->next = NULL;

    if(front == NULL){
        front = nn;
        rear = nn;
    }
    else{
        rear->next = nn;
        rear = nn;
    }
}

void display(){
    node *temp = front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    int n,x;
    printf("enter number of elements: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&x);
        enque(x);
    }

    display();
    return 0;
}
