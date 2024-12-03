#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* NodePtr;

NodePtr createNode() {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    printf("Enter the data to be entered: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

NodePtr insertFront(NodePtr head) {
    NodePtr newNode = createNode();
    newNode->next = head;
    return newNode;
}

NodePtr insertRear(NodePtr head) {
    NodePtr newNode = createNode(), temp = head;
    if(!head) return newNode;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

NodePtr deleteFront(NodePtr head) {
    NodePtr temp = head;
    if(!head) {
        printf("\nEmpty SLL\n");
        return NULL;
    }
    printf("\nDeleted Data: %d", head->data);
    head = head->next;
    free(temp);
    return head;
}

NodePtr deleteRear(NodePtr head) {
    NodePtr prev = NULL, temp = head;
    if(!head) {
        printf("\nEMPTY SLL\n");
        return NULL;
    }
    if(!head->next) {
        printf("\nDeleted Data: %d", head->data);
        free(head);
        return NULL;
    }
    while(temp->next) {
        prev = temp;
        temp = temp->next;
    }
    printf("\nDeleted Data: %d", temp->data);
    prev->next = NULL;
    free(temp);
    return head;
}

void displayNode(NodePtr node) {
    printf("Data:  %d\n", node->data);
}

void displayAll(NodePtr head) {
    NodePtr temp = head;
    if(!head) {
        printf("\nEmpty SLL\n");
        return;
    }
    int count = 0;
    while(temp) {
        displayNode(temp);
        temp = temp->next;
        count++;
    }
    printf("\nThe Number Of Nodes: %d", count);
}

int main() {
    NodePtr head = NULL;
    int choice;

    while(1) {
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
            case 1: head = insertFront(head);
                    break;
            case 2: head = insertRear(head);
                    break;
            case 3: head = deleteFront(head);
                    break;
            case 4: head = deleteRear(head);
                    break;
            case 5: displayAll(head);
                    break;
            case 6: exit(0);
            default: printf("\nINVALID CHOICE\n");
        }
    }
    return 0;
}