/*
Problem Statement:
Construct binary tree from inorder and postorder traversal
and print level order output.

Example:
Input:
5
9 3 15 20 7
9 15 7 20 3

Output:
3 9 20 null null 15 7
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
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

// Search
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
struct Node* build(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    int curr = postorder[*postIndex];
    (*postIndex)--;

    struct Node* node = createNode(curr);

    if (start == end)
        return node;

    int inIndex = search(inorder, start, end, curr);

    node->right = build(inorder, postorder, inIndex + 1, end, postIndex);
    node->left = build(inorder, postorder, start, inIndex - 1, postIndex);

    return node;
}

// Queue for level order
struct Node* queue[3000];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

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

    struct Node* root = build(inorder, postorder, 0, n - 1, &postIndex);

    printf("Level order output:\n");
    printLevelOrder(root);

    return 0;
}