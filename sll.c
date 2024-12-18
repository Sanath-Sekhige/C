#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char usn[20];
    char name[50];
    char branch[50];
    int sem;
    char phNo[15];
    struct Node* next;
} Node;

typedef Node* NodePtr;

NodePtr createNode() {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    printf("Enter USN: ");
    scanf("%s", newNode->usn);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Branch: ");
    scanf("%s", newNode->branch);
    printf("Enter Semester: ");
    scanf("%d", &newNode->sem);
    printf("Enter Phone Number: ");
    scanf("%s", newNode->phNo);
    newNode->next = NULL;
    return newNode;
}

NodePtr insertFront(NodePtr head) {
    NodePtr newNode = createNode();
    newNode->next = head;
    return newNode;
}

NodePtr insertRear(NodePtr head) {
    NodePtr newNode = createNode();
    if (!head) {
        return newNode;
    }

    NodePtr temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

NodePtr deleteFront(NodePtr head) {
    if (!head) {
        printf("\nEmpty SLL\n");
        return NULL;
    }

    NodePtr temp = head;
    printf("\nDeleted Data: USN: %s, Name: %s, Branch: %s, Sem: %d, PhNo: %s\n", 
            head->usn, head->name, head->branch, head->sem, head->phNo);
    head = head->next;
    free(temp);
    return head;
}

NodePtr deleteRear(NodePtr head) {
    if (!head) {
        printf("\nEmpty SLL\n");
        return NULL;
    }
    if (!head->next) {
        printf("\nDeleted Data: USN: %s, Name: %s, Branch: %s, Sem: %d, PhNo: %s\n", 
                head->usn, head->name, head->branch, head->sem, head->phNo);
        free(head);
        return NULL;
    }

    NodePtr prev = NULL, temp = head;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    printf("\nDeleted Data: USN: %s, Name: %s, Branch: %s, Sem: %d, PhNo: %s\n", 
            temp->usn, temp->name, temp->branch, temp->sem, temp->phNo);
    prev->next = NULL;
    free(temp);
    return head;
}

void displayNode(NodePtr node) {
    printf("USN: %s, Name: %s, Branch: %s, Sem: %d, PhNo: %s\n", 
            node->usn, node->name, node->branch, node->sem, node->phNo);
}

void displayAll(NodePtr head) {
    if (!head) {
        printf("\nEmpty SLL\n");
        return;
    }

    int count = 0;
    NodePtr temp = head;
    while (temp) {
        displayNode(temp);
        temp = temp->next;
        count++;
    }
    printf("\nThe Number of Nodes: %d\n", count);
}

int main() {
    NodePtr head = NULL;
    int choice;

    while (1) {
        printf("\nSLL OPERATIONS\n");
        printf("1 ---> INSERT_FRONT\n"
               "2 ---> INSERT_REAR\n"
               "3 ---> DELETE_FRONT\n"
               "4 ---> DELETE_REAR\n"
               "5 ---> DISPLAY\n"
               "6 ---> EXIT\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                head = insertFront(head);
                break;
            case 2:
                head = insertRear(head);
                break;
            case 3:
                head = deleteFront(head);
                break;
            case 4:
                head = deleteRear(head);
                break;
            case 5:
                displayAll(head);
                break;
            case 6:
                exit(0);
            default:
                printf("\nINVALID CHOICE\n");
        }
    }
    return 0;
}