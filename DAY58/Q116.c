/*
Problem Statement:
Construct binary tree from preorder and inorder traversal
and print output in level order format.

Example:
Input:
5
3 9 20 15 7
9 3 15 20 7

Output:
3 9 20 null null 15 7
*/

#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Search in inorder
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
struct Node* build(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;

    int curr = preorder[*preIndex];
    (*preIndex)++;

    struct Node* node = createNode(curr);

    if (start == end)
        return node;

    int inIndex = search(inorder, start, end, curr);

    node->left = build(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = build(preorder, inorder, inIndex + 1, end, preIndex);

    return node;
}

// Queue for level order
struct Node* queue[3000];
int front = 0, rear = 0;

// Enqueue
void enqueue(struct Node* node) {
    queue[rear++] = node;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Print level order
void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (front < rear) {
        struct Node* curr = dequeue();

        if (curr == NULL) {
            printf("null ");
            continue;
        }

        printf("%d ", curr->val);

        enqueue(curr->left);
        enqueue(curr->right);
    }
}

// Main
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter preorder:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Enter inorder:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;

    struct Node* root = build(preorder, inorder, 0, n - 1, &preIndex);

    printf("Level order output:\n");
    printLevelOrder(root);

    return 0;
}