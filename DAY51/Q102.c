/*
Given a Binary Search Tree (BST), find the Lowest Common Ancestor (LCA)
of two given nodes.

According to definition:
“The lowest common ancestor is defined between two nodes p and q as the
lowest node in T that has both p and q as descendants (a node can be a descendant of itself).”

Input Format:
- First line contains integer N
- Second line contains N space-separated integers (BST insertion order)
- Third line contains two node values p and q

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6
*/

#include <stdio.h>
#include <stdlib.h>

// BST Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Find LCA
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (p < root->data && q < root->data)
        return findLCA(root->left, p, q);

    if (p > root->data && q > root->data)
        return findLCA(root->right, p, q);

    return root;
}

int main() {
    int N;
    printf("Enter number of nodes: ");
    scanf("%d", &N);

    struct Node* root = NULL;

    printf("Enter %d elements of BST: ", N);
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        root = insert(root, val);
    }

    int p, q;
    printf("Enter two node values (p and q): ");
    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("LCA is: %d\n", lca->data);
    else
        printf("LCA not found.\n");

    return 0;
}