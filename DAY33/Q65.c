/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

char pop()
{
    char x;
    x = stack[top];
    top--;
    return x;
}

int precedence(char x)
{
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i=0, j=0;
    char ch;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        ch = infix[i];

        if(isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            pop();
        }
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j] = pop();
                j++;
            }
            push(ch);
        }

        i++;
    }

    while(top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}