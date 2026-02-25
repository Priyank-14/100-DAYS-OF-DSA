/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:
Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
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
        printf("Memory allocation is failed!\n");
        exit(1);
    }
    nn->data = value;
    nn->next = NULL;
    return nn;
}

node* detectcycle(node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    node* fast = head;
    node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main(){
    int n,pos,value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    if(n<=0){
        printf("no cycle\n");
        return 0;
    }

    node* head=NULL, *temp=NULL, *nn=NULL, *cyclenode = NULL;

    printf("Enter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&value);

        nn = createnode(value);

        if(head==NULL){
            head = nn;
            temp = nn;
        }
        else{
            temp->next = nn;
            temp = nn;
        }
    }

    printf("Enter the position you want to link: ");
    scanf("%d",&pos);

    if(pos != -1){
        temp = head;
        for(int i=0;i<pos;i++){
            temp = temp->next;
        }
        cyclenode = temp;
        node* last = head;
        while(last->next!= NULL){
            last = last->next;
        }
        last->next = cyclenode;
    }

    node* result = detectcycle(head);
    if(result == NULL){
        printf("No cycle\n");
    }
    else{
        printf("tail connects to node with value %d", result->data);
    }

    return 0;
}
