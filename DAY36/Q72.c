/*Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
}MyCircularDeque;

MyCircularDeque* createDeque(int k){
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->arr = (int*)malloc(sizeof(int)*k);
    obj->capacity = k;
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;
    return obj;
}

bool insertFront(MyCircularDeque* obj, int value){
    if(obj->size == obj->capacity){
        printf("Deque is Full\n");
        return false;
    }

    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->front] = value;
    obj->size++;

    if(obj->size == 1)
        obj->rear = obj->front;

    return true;
}

bool insertLast(MyCircularDeque* obj, int value){
    if(obj->size == obj->capacity){
        printf("Deque is Full\n");
        return false;
    }

    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->arr[obj->rear] = value;
    obj->size++;

    if(obj->size == 1)
        obj->front = obj->rear;

    return true;
}

bool deleteFront(MyCircularDeque* obj){
    if(obj->size == 0){
        printf("Deque is Empty\n");
        return false;
    }

    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

bool deleteLast(MyCircularDeque* obj){
    if(obj->size == 0){
        printf("Deque is Empty\n");
        return false;
    }

    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;
    return true;
}

int getFront(MyCircularDeque* obj){
    if(obj->size == 0)
        return -1;

    return obj->arr[obj->front];
}

int getRear(MyCircularDeque* obj){
    if(obj->size == 0)
        return -1;

    return obj->arr[obj->rear];
}

bool isEmpty(MyCircularDeque* obj){
    return obj->size == 0;
}

bool isFull(MyCircularDeque* obj){
    return obj->size == obj->capacity;
}

void display(MyCircularDeque* obj){
    if(obj->size == 0){
        printf("Deque is Empty\n");
        return;
    }

    int i = obj->front;
    for(int count = 0; count < obj->size; count++){
        printf("%d ", obj->arr[i]);
        i = (i + 1) % obj->capacity;
    }
    printf("\n");
}

int main(){
    int k, choice, value;

    printf("Enter size of circular deque: ");
    scanf("%d",&k);

    MyCircularDeque* dq = createDeque(k);

    while(1){
        printf("\n--- Circular Deque Menu ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Last\n");
        printf("3. Delete Front\n");
        printf("4. Delete Last\n");
        printf("5. Get Front\n");
        printf("6. Get Rear\n");
        printf("7. Check Empty\n");
        printf("8. Check Full\n");
        printf("9. Display\n");
        printf("10. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                insertFront(dq,value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&value);
                insertLast(dq,value);
                break;

            case 3:
                deleteFront(dq);
                break;

            case 4:
                deleteLast(dq);
                break;

            case 5:
                printf("Front element: %d\n", getFront(dq));
                break;

            case 6:
                printf("Rear element: %d\n", getRear(dq));
                break;

            case 7:
                if(isEmpty(dq))
                    printf("Deque is Empty\n");
                else
                    printf("Deque is Not Empty\n");
                break;

            case 8:
                if(isFull(dq))
                    printf("Deque is Full\n");
                else
                    printf("Deque is Not Full\n");
                break;

            case 9:
                printf("Deque elements: ");
                display(dq);
                break;

            case 10:
                free(dq->arr);
                free(dq);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}