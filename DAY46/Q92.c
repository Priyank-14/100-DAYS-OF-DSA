/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000*/

#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create node
struct TreeNode* createNode(int val) {
    if (val == -1) return NULL;

    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for building tree + traversal
struct TreeNode* queue[2000];
int front = 0, rear = 0;

// Insert into queue
void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

// Remove from queue
struct TreeNode* dequeue() {
    return queue[front++];
}

// Build tree from level order input
struct TreeNode* buildTree(int n) {
    if (n == 0) return NULL;

    int val;
    printf("Enter root value: ");
    scanf("%d", &val);

    struct TreeNode* root = createNode(val);
    enqueue(root);

    while (front < rear) {
        struct TreeNode* curr = dequeue();

        int leftVal, rightVal;

        printf("Enter left child of %d (-1 for NULL): ", curr->val);
        scanf("%d", &leftVal);

        printf("Enter right child of %d (-1 for NULL): ", curr->val);
        scanf("%d", &rightVal);

        curr->left = createNode(leftVal);
        curr->right = createNode(rightVal);

        if (curr->left) enqueue(curr->left);
        if (curr->right) enqueue(curr->right);
    }

    return root;
}

// Level Order Traversal
void levelOrder(struct TreeNode* root) {
    if (!root) return;

    front = rear = 0;
    enqueue(root);

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue();
            printf("%d ", node->val);

            if (node->left) enqueue(node->left);
            if (node->right) enqueue(node->right);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    front = rear = 0;

    struct TreeNode* root = buildTree(n);

    printf("\nLevel Order Traversal:\n");
    levelOrder(root);

    return 0;
}