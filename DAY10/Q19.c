/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.
Input:
- Single line: string s
Output:
- Print YES if palindrome, otherwise NO
Example:
Input:
level
Output:
YES
Explanation: String reads same forwards and backwards*/
#include<stdio.h>
#include<string.h>
int main(){
    char s[1000];
    printf("Enter a string: ");
    scanf("%s",s);
    int left=0;
    int right=strlen(s)-1;
    int isPalin=1;
    while(left<right){
        if(s[left]!=s[right]){
            isPalin=0;
            break;
        }
        left++;
        right--;
    }
    if(isPalin==1){
        printf("True");
    }
    else{
        printf("No");
    }
    return 0;
}