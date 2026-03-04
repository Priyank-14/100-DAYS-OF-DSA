/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *stack;
    int *minStack;
    int top;
    int capacity;
} MinStack;

MinStack* minStackCreate(int capacity) {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = capacity;
    obj->stack = (int*)malloc(sizeof(int) * capacity);
    obj->minStack = (int*)malloc(sizeof(int) * capacity);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;

    if (obj->top == 0)
        obj->minStack[obj->top] = val;
    else {
        if (val < obj->minStack[obj->top - 1])
            obj->minStack[obj->top] = val;
        else
            obj->minStack[obj->top] = obj->minStack[obj->top - 1];
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    obj->top--;
}

int minStackTop(MinStack* obj) {
    if (obj->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    if (obj->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return obj->minStack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}

int main() {
    int capacity;
    printf("Enter stack capacity: ");
    scanf("%d", &capacity);

    MinStack* stack = minStackCreate(capacity);

    int choice, value;

    do {
        printf("\n1. Push\n2. Pop\n3. Top\n4. Get Minimum\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                minStackPush(stack, value);
                break;

            case 2:
                minStackPop(stack);
                break;

            case 3:
                printf("Top element: %d\n", minStackTop(stack));
                break;

            case 4:
                printf("Minimum element: %d\n", minStackGetMin(stack));
                break;

            case 5:
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 5);

    minStackFree(stack);

    return 0;
}