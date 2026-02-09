/*Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
Constraints:
1 <= s.length <= 105
s[i] is a printable ascii character.*/
#include <stdio.h>
#include <string.h>

void reverseString(char s[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

int main() {
    char s[10000];
    printf("Enter string: ");
    scanf("%s", s);
    int n = strlen(s);
    reverseString(s, n);
    printf("Reversed string: %s\n", s);
    return 0;
}

