/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createnode(int value){
    node* nn = (node*)malloc(sizeof(node));
    if(!nn){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    nn->data = value;
    nn->next = NULL;
    return nn;
}

int intersectnode(node* head1, node* head2){
    while(head2 != NULL){
        node* temp = head1;
        while(temp != NULL){
        if(head2->data == temp->data){
            printf("Intersection Node is: %d",temp->data);
            return 0;
        }
        temp = temp->next;
    }
    head2 = head2->next;
 }
 printf("No intersection\n");
}

int main(){
    int n,m,value;
    node* head1 = NULL, *head2 = NULL, *nn = NULL, *temp = NULL;

    printf("Enter number of nodes in first linked list: ");
    scanf("%d",&n);

    printf("Enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&value);

        nn = createnode(value);

        if(head1==NULL){
            head1 = nn;
            temp = nn;
        }
        else{
            temp->next = nn;
            temp = nn;
        }
    }

    printf("Enter number of nodes in second linked list: ");
    scanf("%d",&m);

    printf("Enter elements\n");
    for(int i=0;i<m;i++){
        scanf("%d",&value);

        nn = createnode(value);

        if(head2==NULL){
            head2 = nn;
            temp = nn;
        }
        else{
            temp->next = nn;
            temp = nn;
        }
    }

    intersectnode(head1,head2);
    return 0;
}