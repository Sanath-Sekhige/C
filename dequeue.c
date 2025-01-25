#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int DQ_Full(int count) { 
    return count == SIZE; 
}

int DQ_Empty(int count) { 
    return !count; 
}

void insertRear(int DQ[], int* rear, int* count) {
    if(DQ_Full(*count)) {
        printf("\nDEQUEUE FULL\n");
        return;
    }
    int val;
    printf("\nEnter Value: ");
    scanf("%d", &val);
    *rear = (*rear + 1) % SIZE;
    DQ[*rear] = val;
    (*count)++;
}

void deleteFront(int DQ[], int* front, int* count) {
    if(DQ_Empty(*count)) {
        printf("\nDEQUEUE EMPTY\n");
        return;
    }
    printf("\nValue Deleted: %d\n", DQ[*front]);
    *front = (*front + 1) % SIZE;
    (*count)--; 
}

void insertFront(int DQ[], int* front, int* count) {
    if(DQ_Full(*count)) {
        printf("\nDEQUEUE FULL\n");
        return;
    }
    int val;
    printf("\nEnter Value: ");
    scanf("%d", &val);
    *front = (*front - 1 + SIZE) % SIZE;
    DQ[*front] = val;
    (*count)++;
}

void deleteRear(int DQ[], int* rear, int* count) {
    if(DQ_Empty(*count)) {
        printf("\nDEQUEUE EMPTY\n");
        return;
    }
    printf("\nValue Deleted: %d\n", DQ[*rear]);
    *rear = (*rear - 1 + SIZE) % SIZE;
    (*count)--; 
}

void DQ_Dis(int DQ[], int front, int count) {
    if(DQ_Empty(count)) {
        printf("\nDEQUEUE EMPTY\n");
        return;
    }
    for(int i = 0; i < count; i++) {
        printf("%d ", DQ[(front + i) % SIZE]);
    }
    printf("\n");
}

int main() {
    int DQ[SIZE], front = 0, rear = -1, choice, count = 0;

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
            case 1: insertRear(DQ, &rear, &count);
                    break;
            case 2: deleteFront(DQ, &front, &count); 
                    break;
            case 3: insertFront(DQ, &front, &count); 
                    break;
            case 4: deleteRear(DQ, &rear, &count); 
                    break;
            case 5: DQ_Dis(DQ, front, count); 
                    break;
            case 6: exit(0);
            default: printf("\nINVALID CHOICE\n");
        }
    }
    return 0;
}
