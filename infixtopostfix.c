#include <stdio.h>

int precedence(char operator)
{
    if (operator=='+' || operator=='-')
        return 1;
    else if (operator =='*' || operator =='/')
        return 2;
    else if (operator == '^')
        return 3;
    else if (operator =='(')
        return 0;
    else if (operator ==')')
        return -1;
    return -1;
}

void read_infix(char infix[100])
{
    printf("Enter the infix expression string with no gaps:");
    scanf("%s",infix); 
}

int topostfix(char infix[100],char postfix[100],char stack[100], int top)
{
    int i=0,j=0;
    while (infix[i]!='\0')
    {

        if (infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^' || infix[i]==')' || infix[i]=='(')
        {
            if (infix[i]==')')
            {
                while(stack[top]!='(')
                {
                    postfix[j++]=stack[top--];
                }
                top--;
                i++;
            }
            if (infix[i]=='(')
            {
                stack[++top]=infix[i];
                i++;
            }
            else
            {
                if (precedence(infix[i])>precedence(stack[top]))
                {
                    stack[++top]=infix[i];
                    i++;
                }
                else
                {
                    postfix[j++]=stack[top--];
                    stack[++top]=infix[i];
                    i++;
                }
            }
        }
        else 
        {
            postfix[j++]=infix[i];
            i++;
        }
    }
    while(top>=0)
    {
        postfix[j++]=stack[top--];
    }
    postfix[j] = '\0';
    return 0;
}

void main()
{
    char infix[100],postfix[100],stack[100];
    int top=-1;
    read_infix(infix);
    topostfix(infix,postfix,stack,top);
    printf("Postfix expression:%s\n",postfix);
}