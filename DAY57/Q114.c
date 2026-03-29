/*
Problem Statement:
Flatten a binary tree into a linked list in preorder.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (level-order, -1 for NULL)

Output Format:
- Print flattened tree (right pointers only)

Example:
Input:
7
1 2 5 3 4 -1 6

Output:
1 2 3 4 5 6
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

// Helper function
void flattenHelper(struct Node* root, struct Node** prev) {
    if (root == NULL)
        return;

    flattenHelper(root->right, prev);
    flattenHelper(root->left, prev);

    root->right = *prev;
    root->left = NULL;
    *prev = root;
}

// Flatten function
void flatten(struct Node* root) {
    struct Node* prev = NULL;  // reset every time
    flattenHelper(root, &prev);
}

// Print flattened list
void printList(struct Node* root) {
    printf("Flattened Tree: ");
    while (root != NULL) {
        printf("%d ", root->data);
        root = root->right;
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

    flatten(root);

    printList(root);

    return 0;
}