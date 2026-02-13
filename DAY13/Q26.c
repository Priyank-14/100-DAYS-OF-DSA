/*Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100*/
#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int rows, int cols, int* returnSize) {
    int total = rows * cols;
    int *ans = (int*)malloc(sizeof(int) * total);

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int k = 0;

    while (top <= bottom && left <= right) {

        for (int j = left; j <= right; j++)
            ans[k++] = matrix[top][j];
        top++;

        for (int i = top; i <= bottom; i++)
            ans[k++] = matrix[i][right];
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                ans[k++] = matrix[bottom][j];
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans[k++] = matrix[i][left];
            left++;
        }
    }

    *returnSize = total;
    return ans;
}

int main() {
    int r, c;

    printf("Enter number of rows: ");
    scanf("%d", &r);

    printf("Enter number of columns: ");
    scanf("%d", &c);

    int **matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int returnSize;
    int *result = spiralOrder(matrix, r, c, &returnSize);

    printf("Spiral order output: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    for (int i = 0; i < r; i++)
        free(matrix[i]);
    free(matrix);
    free(result);

    return 0;
}
