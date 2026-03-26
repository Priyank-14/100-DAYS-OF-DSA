/*
Problem Statement:
Given the root of a binary tree, print the zigzag level order traversal
of its nodes' values (left to right, then right to left alternately).

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (level-order, -1 for NULL)

Output Format:
- Print zigzag level order traversal (each level in new line)

Example:
Input:
7
3 9 20 -1 -1 15 7

Output:
3
20 9
15 7
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

// Build tree from level order
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

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    printf("Zigzag Level Order Traversal:\n");

    while (front < rear) {
        int size = rear - front;

        int level[size];

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            int index = leftToRight ? i : (size - 1 - i);
            level[index] = curr->data;

            if (curr->left)
                queue[rear++] = curr->left;

            if (curr->right)
                queue[rear++] = curr->right;
        }

        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }
        printf("\n");

        leftToRight = !leftToRight;
    }
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

    zigzagTraversal(root);

    return 0;
}