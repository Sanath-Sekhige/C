#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int Q_Full(int rear) {
    return rear == SIZE - 1;
}

int Q_Empty(int rear, int front) {
    return front > rear;
}

void insert_rear(int Q[], int* rear) {
    if(Q_Full(*rear)) {
        printf("\nQUEUE IS FULL\n");
    } else {
        int val;
        printf("\nEnter element to insert from rear: ");
        scanf("%d", &val);
        Q[++(*rear)] = val;
    }
}

void delete_front(int Q[], int* rear, int* front) {
    if(Q_Empty(*rear, *front)) {
        printf("\nQUEUE IS EMPTY\n");
    } else {
        printf("Deleted from front: %d", Q[(*front)++]);
        if(*front > *rear) {
            *front = 0;
            *rear = -1;
        }
    }
}

void insert_front(int Q[], int* rear, int* front) {
    if(*front == 0 && *rear == -1) {
        int val;
        printf("\nEnter element to insert from front: ");
        scanf("%d", &val);
        Q[++(*rear)] = val;
    } else if(*front) {
        int val;
        printf("\nEnter element to insert from front: ");
        scanf("%d", &val);
        Q[--(*front)] = val;
    } else {
        printf("\nQUEUE IS FULL\n");
    }
}

void delete_rear(int Q[], int* rear, int* front) {
    if(Q_Empty(*rear, *front)) {
        printf("\nQUEUE IS EMPTY\n");
    } else {
        printf("Deleted from rear: %d", Q[(*rear)--]);
        if(*front > *rear) {
            *front = 0;
            *rear = -1;
        }
    }
}

void Q_Dis(int Q[], int rear, int front) {
    if(Q_Empty(rear, front)) {
        printf("\nQUEUE IS EMPTY\n");
    } else {
        printf("\nCONTENTS OF QUEUE\n");
        for(int i = front; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}

int main() {
    int Q[SIZE], rear = -1, front = 0, choice;

    while(1) {
        printf("\nDEQUEUE OPERATIONS\n");
        printf("1 ---> INSERT-REAR\n"
                "2 ---> DELETE-FRONT\n"
                "3 ---> INSERT-FRONT\n"
                "4 ---> DELETE-REAR\n"
                "5 ---> DISPLAY\n"
                "6 ---> EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                insert_rear(Q, &rear);
                break;
            case 2: 
                delete_front(Q, &rear, &front);
                break;
            case 3: 
                insert_front(Q, &rear, &front);
                break;
            case 4: 
                delete_rear(Q, &rear, &front);
                break;
            case 5: 
                Q_Dis(Q, rear, front);
                break;
            case 6: 
                exit(0);
            default: 
                printf("\nINVALID CHOICE\n");
        }
    }
    return 0;
}
