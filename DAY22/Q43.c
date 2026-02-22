/*Problem: Count Nodes in Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

node* createnode(int value){
    node* nn = (node*)malloc(sizeof(node));
    if(!nn){
        printf("Memory allocation failed!\n");
    }
    nn->data = value;
    nn->next = NULL;
    return nn;
}

int countnodes(node* head){
    int count = 0;
    node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void printlist(node* head){
    node* temp = head;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp = temp->next;
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
            head=nn;
            temp = head;
        }
        
        else{
            temp->next=nn;
            temp = nn;
        }
    }

    printf("No. of nodes in the list are: %d\n",countnodes(head));
    printf("Nodes are: ");
    printlist(head);
    printf("\n");

    return 0;
}