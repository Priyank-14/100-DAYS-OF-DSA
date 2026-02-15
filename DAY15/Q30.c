/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.
Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1*/
#include<stdio.h>
void setZeroes(int m, int n, int mat[m][n])
{
    int firstRowZero = 0;
    int firstColZero = 0;

    for(int j = 0; j < n; j++)
        if(mat[0][j] == 0)
            firstRowZero = 1;

    for(int i = 0; i < m; i++)
        if(mat[i][0] == 0)
            firstColZero = 1;

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(mat[i][j] == 0) {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(mat[i][0] == 0 || mat[0][j] == 0)
                mat[i][j] = 0;
        }
    }

    if(firstRowZero)
        for(int j = 0; j < n; j++)
            mat[0][j] = 0;

    if(firstColZero)
        for(int i = 0; i < m; i++)
            mat[i][0] = 0;
}

int main(){
    int m,n;
    printf("Enter number of rows: ");
    scanf("%d",&m);
    printf("Enter number of columns: ");
    scanf("%d",&n);
    
    int mat[m][n];
    printf("Enter elements:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("Element[%d][%d]: ",i,j);
            scanf("%d",&mat[i][j]);
        }
    }

     setZeroes(m,n,mat);

    printf("\nMatrix after setting zeroes:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    return 0;

}