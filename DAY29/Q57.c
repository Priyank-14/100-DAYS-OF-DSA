/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/

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
    }
    nn->data = value;
    nn->next = NULL;
    return nn;
}

node* insertatend(node* head, int value){
    node* nn = createnode(value);

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

node* rotatebyk(node* head, int k){
    if(head == NULL || head->next == NULL || k == 0 ){
        return head;
    }
    node* temp = head;
    int length = 1;
    while(temp->next != NULL){
        temp = temp->next;
        length++;
    }
    temp->next = head;

    k=k%length;
    int steps = length-k;

    node* tail = head;
    for(int i=1;i<steps;i++){
        tail = tail->next;
    }

    node* newhead = tail->next;
    tail->next = NULL;
    return newhead;
}

void printlist(node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}

int main(){
    int n,value,k;
    node* head = NULL;

    printf("Enter number of nodes in list: ");
    scanf("%d",&n);

    printf("Enter elements\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertatend(head, value);
    }

    printf("Enter by how many elements to rotate the list: ");
    scanf("%d",&k);

    head = rotatebyk(head,k);

    printlist(head);
    return 0;
}