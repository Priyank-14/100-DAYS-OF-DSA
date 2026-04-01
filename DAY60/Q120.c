/*
Problem:
Minimum cameras required to monitor binary tree.

Input:
- First line: number of nodes
- Second line: level order (-1 for NULL)

Output:
- Minimum cameras required
*/

#include <stdio.h>
#include <stdlib.h>

// Tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for building tree
struct TreeNode* queue[1000];
int front = 0, rear = 0;

void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

struct TreeNode* dequeue() {
    return queue[front++];
}

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct TreeNode* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        struct TreeNode* curr = dequeue();

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }

    return root;
}

// SAME LOGIC AS LEETCODE
int cameras;

int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 2;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1;
    }

    if (left == 1 || right == 1)
        return 2;

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;

    if (dfs(root) == 0)
        cameras++;

    return cameras;
}

// Main
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order (-1 for NULL):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    int result = minCameraCover(root);

    printf("Minimum cameras required: %d\n", result);

    return 0;
}