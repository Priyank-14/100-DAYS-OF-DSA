/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.
Input:
- First line: two integers m and n
- Next m lines: n integers each
Output:
- Print the sum of the primary diagonal elements
Example:
Input:
3 3
1 2 3
4 5 6
7 8 9
Output:
15
Explanation:
1 + 5 + 9 = 15*/
#include<stdio.h>
int main(){
    int r,c;
    printf("Enter number of rows: ");
    scanf("%d",&r);
    printf("Enter number of columns: ");
    scanf("%d",&c);
    if(r!=c){
        printf("Invalid matrix size! Sum of primary diagonal possible only for square matrix");
    }
    int mat[r][c];
    printf("Enter the elements:\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Element[%d][%d]: ",i,j);
            scanf("%d",&mat[i][j]);
        }
    }

    int sum=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==j){
                sum+=mat[i][j];
            }
        }
    }

    printf("Sum of primary diagonal element is: %d\n",sum);
    return 0;

}