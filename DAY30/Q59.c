/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coeff;
    int exp;
    struct node* next;
}node;

node* createnode(int value,int power){
    node* nn = (node*)malloc(sizeof(node));
    if(!nn){
        printf("Memory allocation failed!\n");
        exit(1);
    }
    nn->coeff = value;
    nn->exp = power;
    nn->next = NULL;
    return nn;
}

node* insertend(node* head, int value, int power){
    node* nn = createnode(value,power);
    if(head==NULL){
        return nn;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = nn;
    return head;
}

void display(node* head){
    if(head == NULL){
        printf("0");
    }

    while(head!=NULL){
        printf("%dx^%d",head->coeff,head->exp);
        if(head->next!=NULL){
            printf(" + ");
        }
        head= head->next;
    }
}

int main(){
    int n, value, power;
    node* head = NULL;

    printf("Enter number of elements in polynomial: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter coefficient and power of exponent: ");
        scanf("%d %d",&value,&power);

        head = insertend(head,value,power);
    }

    printf("Polynomial: ");
    display(head);

    return 0;
}