/*
Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.
*/

#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Search in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree using inorder and postorder
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    // Pick root from postorder (last element)
    int curr = postorder[*postIndex];
    (*postIndex)--;

    struct Node* node = createNode(curr);

    // If leaf node
    if (start == end)
        return node;

    // Find index in inorder
    int inIndex = search(inorder, start, end, curr);

    // IMPORTANT: build RIGHT first, then LEFT
    node->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);
    node->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return node;
}

// Print preorder traversal
void printPreorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

// Main function
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("Enter postorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    int postIndex = n - 1;

    // Build tree
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder traversal is:\n");
    printPreorder(root);

    return 0;
}