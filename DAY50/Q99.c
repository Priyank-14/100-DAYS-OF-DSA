/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/


#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search a value in BST
struct Node* search(struct Node* root, int key) {
    // Base case: root is NULL or key found
    if (root == NULL || root->data == key) {
        return root;
    }

    // If key is smaller, search in left subtree
    if (key < root->data) {
        return search(root->left, key);
    }

    // Else search in right subtree
    return search(root->right, key);
}

// Inorder traversal (for display)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nEnter value to search: ");
    scanf("%d", &key);

    struct Node* result = search(root, key);

    if (result != NULL) {
        printf("Value %d found in BST.\n", key);
    } else {
        printf("Value %d not found in BST.\n", key);
    }

    return 0;
}