/*
Problem Statement:
Given a binary tree, return the values of nodes visible from the right side.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (level-order, -1 for NULL)

Output Format:
- Print right side view (top to bottom)

Example:
Input:
7
1 2 3 -1 5 -1 4

Output:
1 3 4
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n)
                nodes[i]->left = nodes[left];

            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }

    return nodes[0];
}

// Right Side View
void rightSideView(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    printf("Right Side View: ");

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            if (i == size - 1)
                printf("%d ", curr->data);

            if (curr->left)
                queue[rear++] = curr->left;

            if (curr->right)
                queue[rear++] = curr->right;
        }
    }

    printf("\n");
}

int main() {
    int N;
    printf("Enter number of nodes: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter level-order traversal (-1 for NULL): ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);

    rightSideView(root);

    return 0;
}