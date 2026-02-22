/*Given the head of a singly linked list, reverse the list, and return the reversed list.
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

node* createnode(int value){
    node* nn= (node*)malloc(sizeof(node));
    if(!nn){
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    nn->data=value;
    nn->next=NULL;
    return nn;
}

node* reverselist(node* head){
    node* prev=NULL;
    node* next=NULL;
    node* curr=head;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printlist(node* head){
    node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int n,value;
    node* head=NULL, *temp=NULL, *nn=NULL;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&value);

        nn = createnode(value);

        if(head==NULL){
            head = nn;
            temp = head;
        }

        else{
            temp->next = nn;
            temp = nn;
        }
    }

    head = reverselist(head);

    printf("Reversed list: ");
    printlist(head);
    printf("\n");

    return 0;
}