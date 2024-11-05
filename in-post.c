#include <stdio.h>
#include <string.h>
#define SIZE 20

int F(char sym)
{
	switch(sym)
	{
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 4;
		case '^':
		case '$': return 5;
		case '(': return 0;
		case '#': return -1;
		default: return 8;
	}
}

int G(char sym)
{
	switch(sym)
	{
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 3;
		case '^':
		case '$': return 6;
		case '(': return 9;
		case ')': return 0;
		default: return 7;
	}
}

void infix_postfix(char infix[], char postfix[])
{
	int top = -1, j = 0;
	char stack[SIZE], sym;
	stack[++top]='#';

	for(int i = 0; i < strlen(infix); i++)
	{
		sym = infix[i];
		while(F(stack[top]) > G(sym)) {
			postfix[j++] = stack[top--];
		}
		F(stack[top]) != G(sym) ? stack[++top] = sym : top--;
	}
	while(stack[top] != '#') {
		postfix[j++] = stack[top--];
    }  
	postfix[j] = '\0';
}

int main()
{
 	char postfix[SIZE], infix[SIZE];
 	printf("Enter the infix expression: ");
 	scanf("%s", infix);
 	infix_postfix(infix, postfix);
 	printf("The Postfix expression is: ");
 	printf("%s", postfix);
    return 0;
 }