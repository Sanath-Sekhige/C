#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void push(int *top, int stack[]) {
	int val;
	if(*top == SIZE - 1) {
		printf("\nSTACK OVERFLOW\n");
		return;
	}
	printf("Enter element to be pushed: ");
	scanf("%d", &val);	
	stack[++(*top)]= val;
}

void pop(int *top, int stack[]) {
	if(*top == -1) {
		printf("\nSTACK UNDERFLOW\n");
		return;
	}
	printf("Element to be deleted: %d\n", stack[(*top)--]);
}

void display(int top, int stack[]) {
	if(top == -1) {
		printf("\nSTACK IS EMPTY\n");
		return;
	}
	printf("Contents of STACK\n");
	for(int i = top; i >= 0; i--) {
        printf("%d\t", stack[i]);
    }
	printf("\n");
}

int main()
{
	int stack[SIZE], choice, top = -1;

	while(1) {
		printf("\nSTACK OPERATIONS\n");
        printf("1 ---> INSERT\n"
               "2 ---> DELETE\n"
               "3 ---> DISPLAY\n"
               "4 ---> EXIT\n");

        printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: push(&top, stack);
					break;
			case 2: pop(&top, stack);
					break;
			case 3: display(top, stack);
					break;
			case 4: exit(0);
            default: printf("\nINVALID CHOICE]\n");
		}
	}
    return 0;
}