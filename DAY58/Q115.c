/*
Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1
*/

#include <stdio.h>
#include <stdlib.h>

// Structure of Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Search element in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree using preorder and inorder
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    int curr = preorder[*preIndex];
    (*preIndex)++;

    struct Node* node = createNode(curr);

    if (start == end)
        return node;

    int inIndex = search(inorder, start, end, curr);

    node->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return node;
}

// Print Postorder
void printPostorder(struct Node* root) {
    if (root == NULL)
        return;

    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}

// Main Function
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter preorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Postorder traversal is:\n");
    printPostorder(root);

    return 0;
}