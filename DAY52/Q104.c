/*
Problem Statement:
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes.

Definition:
“The lowest common ancestor is the lowest node that has both nodes
as descendants (a node can be a descendant of itself).”

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values p and q

Output Format:
- Print the LCA value

Example:
Input:
11
3 5 1 6 2 0 8 -1 -1 7 4
5 1

Output:
3
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

// Build tree from level-order array
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

// Find LCA in Binary Tree
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (root->data == p || root->data == q)
        return root;

    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
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