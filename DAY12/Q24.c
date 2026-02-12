/*Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
Example 1:
Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: true
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:
Input: matrix = [[1,2],[2,2]]
Output: false
Explanation:
The diagonal "[1, 2]" has different elements.
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 20
0 <= matrix[i][j] <= 99
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            if(matrix[i][j] != matrix[i-1][j-1]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Enter matrix elements:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int* matrixColSize = (int*)malloc(rows * sizeof(int));
    for(int i = 0; i < rows; i++){
        matrixColSize[i] = cols;
    }

    bool result = isToeplitzMatrix(matrix, rows, matrixColSize);

    if(result)
        printf("true\n");
    else
        printf("false\n");

    for(int i = 0; i < rows; i++){
        free(matrix[i]);
    }
    free(matrix);
    free(matrixColSize);

    return 0;
}

