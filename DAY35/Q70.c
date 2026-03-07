/*Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node *top1 = NULL;
node *top2 = NULL;

void pushStack(node **top, int x){
    node *nn = (node*)malloc(sizeof(node));
    nn->data = x;
    nn->next = *top;
    *top = nn;
}

int popStack(node **top){
    if(*top == NULL)
        return -1;

    node *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int peekStack(node *top){
    if(top == NULL)
        return -1;
    return top->data;
}

int isEmpty(node *top){
    return top == NULL;
}

/* Queue Operations */

void push(int x){
    pushStack(&top1, x);
}

int pop(){

    if(isEmpty(top2)){
        while(!isEmpty(top1)){
            pushStack(&top2, popStack(&top1));
        }
    }

    return popStack(&top2);
}

int peek(){

    if(isEmpty(top2)){
        while(!isEmpty(top1)){
            pushStack(&top2, popStack(&top1));
        }
    }

    return peekStack(top2);
}

int empty(){
    return isEmpty(top1) && isEmpty(top2);
}

int main(){

    int n,x;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&x);
        push(x);
    }

    printf("\nFront element (peek): %d\n",peek());

    printf("Element removed (pop): %d\n",pop());

    if(empty())
        printf("Queue is empty\n");
    else
        printf("Queue is not empty\n");

    return 0;
}