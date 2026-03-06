/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* top = NULL;

void push(int val){
    node* nn = (node*)malloc(sizeof(node));
    nn->data = val;
    nn->next = top;
    top = nn;
}

int pop(){
    if(top == NULL){
        return -1;
    }

    node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char exp[]){
    char *token = strtok(exp," ");

    while(token != NULL){

        if(isdigit(token[0])){
            push(atoi(token));
        }
        else{
            int b = pop();
            int a = pop();
            int result;

            switch(token[0]){
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(result);
        }

        token = strtok(NULL," ");
    }

    return pop();
}

int main(){
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp,100,stdin);

    exp[strcspn(exp,"\n")] = 0;

    int result = evaluate(exp);

    printf("%d", result);

    return 0;
}