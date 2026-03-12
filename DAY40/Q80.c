/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
*/

#include <stdio.h>
#include <stdlib.h>

void dailyTemperatures(int temps[], int n, int ans[]) {

    int stack[n];
    int top = -1;

    for(int i = 0; i < n; i++)
        ans[i] = 0;

    for(int i = 0; i < n; i++) {

        while(top != -1 && temps[i] > temps[stack[top]]) {
            int index = stack[top--];
            ans[index] = i - index;
        }

        stack[++top] = i;
    }
}

int main() {

    int n;

    printf("Enter number of temperatures: ");
    scanf("%d", &n);

    int temps[n], ans[n];

    printf("Enter temperatures:\n");
    for(int i = 0; i < n; i++) {
        printf("Temperature %d: ", i+1);
        scanf("%d", &temps[i]);
    }

    dailyTemperatures(temps, n, ans);

    printf("\nDays to wait for warmer temperature:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}