/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if (top == -1)
                return false;

            char ch = stack[top--];

            if ((s[i] == ')' && ch != '(') ||
                (s[i] == '}' && ch != '{') ||
                (s[i] == ']' && ch != '[')) {
                return false;
            }
        }
    }

    return top == -1;
}

int main() {
    char s[1000];

    printf("Enter the string containing brackets: ");
    scanf("%s", s);

    if (isValid(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
