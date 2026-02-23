/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/

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

node* insertatend(node* head, int value){
    node* nn = createnode(value);

    if(head==NULL){
        head = nn;
        return head;
    }

    else{
        node* temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
        return head;
    }
}

node* mergelist(node* head1, node* head2){
    node* dummy = createnode(0);
    node* tail = dummy;

    while(head1!=NULL && head2!=NULL){
        if(head1->data <= head2->data){
            tail->next = head1;
            head1 = head1->next;
        }
        else{
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if(head1!=NULL){
        tail->next = head1;
    }
    else{
        tail->next = head2;
    }
    return dummy->next;
}

void printlist(node* head){
    node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    int m,n,value;
    node* head1=NULL;
    node* head2=NULL;

    printf("Enter number of nodes of first list: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&value);
        head1 = insertatend(head1,value);
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        printf("Enter element: ");
        scanf("%d",&value);
        head2 = insertatend(head2,value);
    }

    node* mergedlist = mergelist(head1,head2);

    printf("Merged list\n");
    printlist(mergedlist);

    return 0;
}