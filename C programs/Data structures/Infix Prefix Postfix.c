#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX 20
void infix_to_prefix();
char stack[MAX], infix[MAX], prefix[MAX], postfix[MAX];
int top = -1;

int precedence(char c)
{
    if (c == '+' || c == '-')
        return (1);

    if (c == '*' || c == '/')
        return (2);

    if (c == '^')
        return (3);

    return 0;
}
//function for pushing element into stack
void push(int i)
{
    if (top == MAX - 1)
    {
        printf("\nSTACK OVERFLOW\n");
    }
    else
    {
        top++;
        stack[top] = infix[i];
    }
}

void push2(char i)
{
    if (top == MAX - 1)
    {
        printf("\nSTACK OVERFLOW\n");
    }
    else
    {
        top++;
        stack[top] = infix[i];
    }
}

//function for popping element from the stack
char pop()
{
    char ch;
    if (top < 0)
    {
        printf("\nSTACK UNDERFLOW\n");
        exit(0);
    }
    else
    {
        ch = stack[top];
        stack[top] = '\0';
        top--;
        return (ch);
    }
    return 0;
}
//Function which converts infix to prefix

void toprefix()
{
    int i = 0, j = 0;
    //predefined function for reversing a string
    strrev(infix);
    while (infix[i] != '\0')
    {
        //add reversed array element directly into prefix array it operand
        if (infix[i] >= 'a' && infix[i] <= 'z')
        {
            prefix[j] = infix[i];
            j++;
            i++;
        }
        //if closing bracket then push into the stack
        else if (infix[i] == ')')
        {
            push(i);
            i++;
        }
        //if opening bracket then pop elements from the stack until closing bracket is found
        else if (infix[i] == '(')
        {

            while (stack[top] != ')')
            {
                prefix[j] = pop();
                j++;
            }
            pop();
            i++;
        }
        else
        {
            if (top == -1)
            {
                push(i);
                i++;
            }
            //if current operator has lower precedence than that of the stack top, pop the ele from stack and check this again
            else if (precedence(infix[i]) < precedence(stack[top]))
            {
                prefix[j] = pop();
                j++;
                while (precedence(stack[top]) > precedence(infix[i]))
                {
                    prefix[j] = pop();
                    j++;
                    if (top < 0)
                    {
                        break;
                    }
                }
                push(i);
                i++;
            }
            //if current element has higher or equal precedance than that of top then push current ele into the stack
            else if (precedence(infix[i]) >= precedence(stack[top]))
            {
                push(i);
                i++;
            }
        }
    }
    while (top != -1)
    {
        prefix[j] = pop();
        j++;
    }
    strrev(prefix);
    prefix[j] = '\0';
    printf("PREFIX is-> : %s ", prefix);
}

void topostfix()
{
    char ch, elem;
    int i = 0, k = 0;
    strrev(infix);
    push2('#');
    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
            push2(ch);
        //if current is aplhabet or a num insert it into postfix array
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (stack[top] != '(')
                postfix[k++] = pop();
            elem = pop(); /* Remove ( */
        }
        else
        { /* Operator */
            while (precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push2(ch);
        }
    }
    while (stack[top] != '#') /* Pop from stack till empty */
        postfix[k++] = pop();
    postfix[k] = '\0'; /* Make postfix as valid string */
    printf("\nPostfix Expression =  %s\n", postfix);
}

void main()
{
    printf("\nEnter INFIX -> ");
    gets(infix);
    //toprefix();
    printf("Top-> %d\n", top);

    topostfix();
}
