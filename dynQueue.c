#include <stdio.h>
#include <stdlib.h>

int Q_Full(int rear, int size) {
    return rear == size - 1;
}

int Q_Empty(int front, int rear) {
    return front > rear;
}

void Q_Ins(int **Q, int *rear, int *size) {
    int val;
    if(Q_Full(*rear, *size)) {
        *size *= 2;
        *Q = realloc(*Q, *size * sizeof(int));
        printf("\nIncreased queue size to %d\n", *size);
    }
    
    printf("Enter value to be inserted: ");
    scanf("%d", &val);
    (*Q)[++(*rear)] = val;
}

void Q_Del(int *Q, int *front, int *rear) {
    if(Q_Empty(*front, *rear)) {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }
    printf("\nThe deleted item from QUEUE: %d", Q[(*front)++]);
}

void Q_Dis(int *Q, int front, int rear) {
    if(Q_Empty(front, rear)) {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }
    printf("\nCONTENTS OF QUEUE\n");
    for(int i = front; i <= rear; i++) {
        printf("%d ", Q[i]);
    }
    printf("\n");
}

int main() {
    int *Q = malloc(3 * sizeof(int));
    int front = 0, rear = -1, size = 3, choice;

    while(1) {
        printf("\nQUEUE OPERATIONS\n");
        printf("1 ---> INSERT\n"
               "2 ---> DELETE\n"
               "3 ---> DISPLAY\n"
               "4 ---> EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: Q_Ins(&Q, &rear, &size);
                    break;
            case 2: Q_Del(Q, &front, &rear);
                    break;
            case 3: Q_Dis(Q, front, rear);
                    break;
            case 4: free(Q); exit(0);
            default: printf("\nINVALID CHOICE\n");
        }
    }
    return 0;
}
