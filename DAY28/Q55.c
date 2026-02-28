/*Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
*/

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

node* createcircularlist(int n){
    if(n<=0){
        return NULL;
    }

    node* head = NULL, *temp = NULL;

    for(int i=0;i<n;i++){
        int value;
        printf("Enter value: ");
        scanf("%d",&value);

        node* nn = createnode(value);
         if(head==NULL){
            head = nn;
            temp = nn;
         }
         else{
            temp->next = nn;
            temp = nn;
         }
    }
    temp->next = head;
    return head;
}

void traverse(node* head){
    if(head==NULL){
        printf("List is Empty!\n");
        return;
    }
    node* temp = head;
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!=head);
}

int main(){
    int n;
    printf("Enter number of nodes in circular linked list: ");
    scanf("%d",&n);

    node* head = createcircularlist(n);
    traverse(head);

    return 0;
}


