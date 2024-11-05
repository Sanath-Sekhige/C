#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int Q_Full(int rear) {
    return rear == SIZE - 1;
}

int Q_Empty(int front, int rear) {
    return front > rear;
}

void Q_Ins(int Q[], int* rear) {
    int val;
    if(Q_Full(*rear)) {
        printf("\nQUEUE IS FULL\n");
        return;
    }
    printf("Enter value to be inserted: ");
    scanf("%d", &val);
    Q[++(*rear)] = val;
}

void Q_Del(int Q[], int* front, int* rear) {
    if(Q_Empty(*front, *rear)) {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }
    printf("\nThe deleted item from QUEUE: %d", Q[(*front)++]);
    if(*front > *rear) *front = 0, *rear = -1;
}

void Q_Dis(int Q[], int front, int rear) {
    if(Q_Empty(front, rear)) {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }
    printf("\nCONTENTS OF QUEUE\n");
    for(int i = front; i < rear + 1; i++) {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

int main() {
    int Q[SIZE], front = 0, rear = -1, choice;

    while(1) {
        printf("\nQUEUE OPERATIONS\n");
        printf("1 ---> INSERT\n"
                "2 ---> DELETE\n"
                "3 ---> DISPLAY\n"
                "4 ---> EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: Q_Ins(Q, &rear);
                    break;
            case 2: Q_Del(Q, &front, &rear);
                    break;
            case 3: Q_Dis(Q, front, rear);
                    break;
            case 4: exit(0);
            default: printf("\nINVALID CHOICE\n");
        }
    }
    return 0;
}