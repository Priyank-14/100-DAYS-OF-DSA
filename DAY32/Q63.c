/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int data;
    struct Stack* next;
}stack;

stack* push(stack* top,int value){
    stack* nn = (stack*)malloc(sizeof(stack));
    if(!nn){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    nn->data = value;
    nn->next = top;
    top = nn;
    return top;
}

stack* pop(stack* top){
    if(top==NULL){
        printf("Stack Underflow!\n");
        return top;
    }
    stack* temp = top;
    top = top->next;
    free(temp);
    return top;
}

void display(stack* top){
    printf("Remaining elements of stack from top to bottom:\n");
    while(top!=NULL){
        printf("%d ",top->data);
        top = top->next;
    }
}

int main(){
    stack* top = NULL;
    int n , m , x;

    printf("Enter numbers of elements to push: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        top = push(top,x);
    }

    printf("Enter number of elements to pop: ");
    scanf("%d",&m);

    for(int i=0;i<m;i++){
        top = pop(top);
    }

    display(top);
    return 0;
}