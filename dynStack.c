#include <stdio.h>
#include <stdlib.h>

void push(int **stack, int* top, int* size) {
    if(*top == *size - 1) {
        *size *= 2;
        *stack = realloc(*stack, *size * sizeof(int));
        printf("\nStack size increased -> %d\n", *size);
    }
    int val;
    printf("\nEnter Element to Push: ");
    scanf("%d", &val);
    (*stack)[++(*top)] = val;
}

void pop(int *stack, int *top) {
    if(*top == -1) {
        printf("\nSTACK UNDERFLOW\n");
        return;
    }
    printf("\nElement to Pop: %d\n", stack[(*top)--]);
}

void display(int *stack, int top) {
    if(top == -1) {
        printf("\nSTACK EMPTY\n");
        return;
    }
    printf("\nCONTENTS OF STACK\n");
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int *stack = malloc(3 * sizeof(int));
    int size = 3, top = -1, choice;

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
			case 1: push(&stack, &top, &size);
					break;
			case 2: pop(stack, &top);
					break;
			case 3: display(stack, top);
					break;
			case 4: free(stack);
                    exit(0);
            default: printf("\nINVALID CHOICE\n");
		}
	}
    return 0;
}