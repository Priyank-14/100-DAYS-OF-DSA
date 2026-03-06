/*Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int calculate(char* s) {

    int n = strlen(s);
    int *stack = (int*)malloc(n * sizeof(int));
    int top = -1;

    long num = 0;
    char op = '+';

    for(int i = 0; i < n; i++) {

        if(isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {

            if(op == '+') stack[++top] = num;
            else if(op == '-') stack[++top] = -num;
            else if(op == '*') stack[top] = stack[top] * num;
            else if(op == '/') stack[top] = stack[top] / num;

            op = s[i];
            num = 0;
        }
    }

    int result = 0;

    while(top >= 0) {
        result += stack[top--];
    }

    free(stack);
    return result;
}

int main() {

    char *s = (char*)malloc(300001 * sizeof(char));

    printf("Enter the expression: ");
    fgets(s,300001,stdin);

    int result = calculate(s);

    printf("Result = %d", result);

    free(s);
    return 0;
}