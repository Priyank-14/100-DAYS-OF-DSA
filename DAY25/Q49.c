/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.
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

int main(){
    int n,value;
    node* head=NULL, *temp=NULL, *nn=NULL;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    if(n<=0){
        printf("0");
        return 0;
    }

    printf("Enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        nn=createnode(value);

        if(head==NULL){
            head = nn;
            temp=nn;
        }
        else{
            temp->next=nn;
            temp=nn;
        }
    }

    int key;
    int count=0;
    printf("Enter value to be searched: ");
    scanf("%d",&key);

    temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            count++;
        }
        temp=temp->next;
    }

    printf("Count of %d is : %d",key,count);
    return 0;
}

