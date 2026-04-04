/*
Problem:
Perform flood fill on an image.

Input:
- rows, cols
- matrix
- starting position (sr, sc)
- new color

Output:
- modified image
*/

#include <stdio.h>

// DFS function
void dfs(int image[50][50], int m, int n, int r, int c, int oldColor, int newColor) {
    if (r < 0 || c < 0 || r >= m || c >= n)
        return;

    if (image[r][c] != oldColor)
        return;

    image[r][c] = newColor;

    // 4 directions
    dfs(image, m, n, r+1, c, oldColor, newColor);
    dfs(image, m, n, r-1, c, oldColor, newColor);
    dfs(image, m, n, r, c+1, oldColor, newColor);
    dfs(image, m, n, r, c-1, oldColor, newColor);
}

int main() {
    int m, n;

    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int image[50][50];

    printf("Enter image matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int sr, sc, color;

    printf("Enter starting row and column: ");
    scanf("%d %d", &sr, &sc);

    printf("Enter new color: ");
    scanf("%d", &color);

    int oldColor = image[sr][sc];

    if (oldColor != color) {
        dfs(image, m, n, sr, sc, oldColor, color);
    }

    printf("Modified Image:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}