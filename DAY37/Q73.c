/*Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *pq;
int size = 0;
int capacity;

void insert(int x)
{
    if(size == capacity)
    {
        printf("Queue Overflow\n");
        return;
    }

    int i = size - 1;

    while(i >= 0 && pq[i] > x)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    size++;
}

int deleteElement()
{
    if(size == 0)
        return -1;

    int val = pq[0];

    for(int i = 1; i < size; i++)
        pq[i - 1] = pq[i];

    size--;

    return val;
}

int peek()
{
    if(size == 0)
        return -1;

    return pq[0];
}

int main()
{
    int n;

    printf("Enter number of operations: ");
    scanf("%d",&n);

    capacity = n;
    pq = (int*)malloc(capacity * sizeof(int));

    char operation[20];
    int x;

    for(int i = 0; i < n; i++)
    {
        printf("Enter operation (insert/delete/peek): ");
        scanf("%s",operation);

        if(strcmp(operation,"insert") == 0)
        {
            printf("Enter value to insert: ");
            scanf("%d",&x);
            insert(x);
        }

        else if(strcmp(operation,"delete") == 0)
        {
            int val = deleteElement();
            printf("Deleted Element: %d\n", val);
        }

        else if(strcmp(operation,"peek") == 0)
        {
            int val = peek();
            printf("Top Priority Element: %d\n", val);
        }
    }

    free(pq);
    return 0;
}