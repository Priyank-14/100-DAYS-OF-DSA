/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/

#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX], stack[MAX];
    int front = 0, rear = -1;
    int top = -1;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        queue[++rear] = x;
    }

    // Move queue → stack
    while(front <= rear) {
        stack[++top] = queue[front++];
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Move stack → queue
    while(top >= 0) {
        queue[++rear] = stack[top--];
    }

    printf("Reversed Queue:\n");
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}