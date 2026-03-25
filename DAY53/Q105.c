/*
Problem Statement:
Given a binary tree, print its vertical order traversal.
Nodes that lie on the same vertical line should be printed together
from top to bottom and left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers (level-order traversal, -1 for NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue node (for BFS)
struct QNode {
    struct Node* treeNode;
    int hd; // horizontal distance
};

// Create new tree node
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

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    // Simple arrays for storing result
    int result[200][200];   // store nodes per vertical line
    int count[200] = {0};   // count of nodes per line

    // Offset to handle negative index
    int offset = 100;

    struct QNode queue[1000];
    int front = 0, rear = 0;

    // Push root
    queue[rear++] = (struct QNode){root, 0};

    int min_hd = 0, max_hd = 0;

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.treeNode;
        int hd = temp.hd;

        int index = hd + offset;

        result[index][count[index]++] = curr->data;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        if (curr->left != NULL)
            queue[rear++] = (struct QNode){curr->left, hd - 1};

        if (curr->right != NULL)
            queue[rear++] = (struct QNode){curr->right, hd + 1};
    }

    // Print vertical order
    printf("Vertical Order Traversal:\n");
    for (int i = min_hd; i <= max_hd; i++) {
        int index = i + offset;
        for (int j = 0; j < count[index]; j++) {
            printf("%d ", result[index][j]);
        }
        printf("\n");
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

    verticalOrder(root);

    return 0;
}