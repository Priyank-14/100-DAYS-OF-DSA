/*Problem: Create and Traverse Singly Linked List

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

//define structure
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//creating newnode
Node* createnode(int value){
    Node* nn = (Node*)malloc(sizeof(Node));
    if(!nn){
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    nn->data = value;
    nn->next = NULL;
    return nn;
}

//traverse function
void traverse(Node* head){
    if(head == NULL){
        printf("List is Empty!\n");
    }

    Node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
     int n, value;
     Node* head = NULL, *temp = NULL, *nn = NULL;

     printf("Enter number of nodes: ");
     scanf("%d",&n);

     for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&value);

        nn = createnode(value);

        if (head == NULL) {
            head = nn;
            temp = nn;
        } 
        
        else {
            temp->next = nn;
            temp = nn;
        }
    }

    traverse(head);

    return 0;
}
