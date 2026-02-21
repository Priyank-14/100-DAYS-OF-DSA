/*Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createnode(int value){
    Node* nn = (Node*)malloc(sizeof(Node));
    if(!nn){
        printf("Memory Allocation Failed!\n");
    }

    nn->data = value;
    nn->next = NULL;
    return nn;
}

Node* findmiddle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void traverse(Node* head){
    while(head!= NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}

int main(){
    int n,value;
    Node* head=NULL, *temp=NULL, *nn=NULL;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter elements: ");
        scanf("%d",&value);

        nn = createnode(value);

        if(head == NULL){
            head = nn;
            temp = nn;
        }
        
        else{
            temp->next = nn;
            temp = nn;
        }
    }

    Node* middle = findmiddle(head);

    traverse(middle);

    return 0;
}