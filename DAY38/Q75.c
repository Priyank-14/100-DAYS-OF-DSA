/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/

#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isFull()
{
    if((front == 0 && rear == MAX-1) || (front == rear + 1))
        return 1;
    return 0;
}

int isEmpty()
{
    if(front == -1)
        return 1;
    return 0;
}

void push_front(int value)
{
    if(isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;

    else if(front == 0)
        front = MAX-1;

    else
        front--;

    deque[front] = value;
}

void push_back(int value)
{
    if(isFull())
    {
        printf("Deque Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;

    else if(rear == MAX-1)
        rear = 0;

    else
        rear++;

    deque[rear] = value;
}

void pop_front()
{
    if(isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if(front == rear)
        front = rear = -1;

    else if(front == MAX-1)
        front = 0;

    else
        front++;
}

void pop_back()
{
    if(isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;

    else if(rear == 0)
        rear = MAX-1;

    else
        rear--;
}

void display()
{
    if(isEmpty())
    {
        printf("Deque is Empty\n");
        return;
    }

    int i = front;

    printf("Deque elements: ");

    while(1)
    {
        printf("%d ", deque[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int getFront()
{
    if(isEmpty())
        return -1;
    return deque[front];
}

int getBack()
{
    if(isEmpty())
        return -1;
    return deque[rear];
}

int size()
{
    if(isEmpty())
        return 0;

    if(rear >= front)
        return rear - front + 1;

    return MAX - front + rear + 1;
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n----- DEQUE MENU -----\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Pop Front\n");
        printf("4. Pop Back\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Size\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                printf("Front element: %d\n", getFront());
                break;

            case 6:
                printf("Rear element: %d\n", getBack());
                break;

            case 7:
                printf("Size: %d\n", size());
                break;

            case 8:
                display();
                break;

            case 9:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }

    return 0;
}