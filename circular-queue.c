#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int Q_Full(int count) {
    return count == SIZE;
}

int Q_Empty(int count) {
    return !count;
}

void Q_Ins(int Q[], int* rear, int* count)
{
    int val;
    if (Q_Full(*count)) {
        printf("\nQUEUE IS FULL\n");
        return;
    }

    printf("Enter value to be inserted: ");
    scanf("%d", &val);
    *rear = (*rear + 1) % SIZE;
    Q[*rear] = val;
    (*count)++;
}

void Q_Del(int Q[], int* front, int* count)
{
    if (Q_Empty(*count)) {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }

    printf("\nItem deleted from QUEUE: %d\n", Q[*front]);
    *front = (*front + 1) % SIZE;
    (*count)--;
}

void Q_Dis(int Q[], int front, int count)
{
    if (Q_Empty(count)) {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }

    printf("\nCONTENTS OF QUEUE\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t", Q[(front + i) % SIZE]);
    }
}

int main() {
    int Q[SIZE], choice, front = 0, rear = -1, count = 0;

    while (1) {
        printf("\nQUEUE OPERATIONS\n");
        printf("1 ---> INSERT\n"
               "2 ---> DELETE\n"
               "3 ---> DISPLAY\n"
               "4 ---> EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    
        switch (choice) {
            case 1: Q_Ins(Q, &rear, &count);
                break;
            case 2: Q_Del(Q, &front, &count);
                break;
            case 3: Q_Dis(Q, front, count);
                break;
            case 4: exit(0);
            default: printf("\nINVALID CHOICE\n");
        }
    }
	return 0;
}