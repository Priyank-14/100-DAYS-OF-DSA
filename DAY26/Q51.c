/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;

node* createnode(int value){
    node* nn = (node*)malloc(sizeof(node));
    if(!nn){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    nn->data = value;
    nn->prev = NULL;
    nn->next = NULL;
    return nn;
}

void traverselist(node* head){
    if(head==NULL){
        printf("Empty list!\n");
    }

    node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    int n, val;
    node* head=NULL, *temp=NULL, *nn=NULL;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&val);

        nn = createnode(val);

        if(head==NULL){
            head = nn;
            temp =nn;
        }

        else{
            temp->next = nn;
            nn->prev = temp;
            temp = nn;
        }
    }

    printf("Elements of linked list after traversal are:\n");
    traverselist(head);

    return 0;
}


