#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define SIZE 20

double compute(double op1, double op2, char symbol)
{
    switch (symbol)
    {
        case '+' : return op1 + op2;
        case '-' : return op1 - op2;
        case '*' : return op1 * op2;
        case '/' : return op1 / op2;
        case '%' : return fmod(op1, op2);
        case '$' : 
        case '^' : return pow(op1, op2);
    }
}

int main()
{
    int top = -1;
    char postfix[SIZE], symbol;
    double stack[SIZE], op1, op2, result;
    printf("\nEnter postfix expression : ");
    scanf("%s",postfix);
    for(int i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];
        if(isdigit(symbol)) {
            stack[++top]=symbol-'0';
        } else {
            op2 = stack[top--];
            op1 = stack[top--];
            result = compute(op1, op2, symbol);
            stack[++top] = result;
        }
    }
    result = stack[top--];
    printf("\nThe result of the expression is : %.4f\n", result);
    return 0;
}