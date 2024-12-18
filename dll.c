#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char ssn[20];
    char name[50];
    char dept[50];
    char designation[50];
    float salary;
    char phNo[15];
    struct Node* next;
    struct Node* prev;
} Node;

typedef Node* NodePtr;

NodePtr createNode() {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    printf("Enter SSN: ");
    scanf("%s", newNode->ssn);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Department: ");
    scanf("%s", newNode->dept);
    printf("Enter Designation: ");
    scanf("%s", newNode->designation);
    printf("Enter Salary: ");
    scanf("%f", &newNode->salary);
    printf("Enter Phone Number: ");
    scanf("%s", newNode->phNo);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

NodePtr insertFront(NodePtr head) {
    NodePtr newNode = createNode();
    if (head) {
        head->prev = newNode;
    }
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
    newNode->prev = temp;
    return head;
}

NodePtr deleteFront(NodePtr head) {
    if (!head) {
        printf("\nEmpty DLL\n");
        return NULL;
    }

    NodePtr temp = head;
    printf("\nDeleted Data: SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, PhNo: %s\n",
           head->ssn, head->name, head->dept, head->designation, head->salary, head->phNo);
    head = head->next;
    if (head) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

NodePtr deleteRear(NodePtr head) {
    if (!head) {
        printf("\nEmpty DLL\n");
        return NULL;
    }
    if (!head->next) {
        printf("\nDeleted Data: SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, PhNo: %s\n",
               head->ssn, head->name, head->dept, head->designation, head->salary, head->phNo);
        free(head);
        return NULL;
    }

    NodePtr temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    printf("\nDeleted Data: SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, PhNo: %s\n",
           temp->ssn, temp->name, temp->dept, temp->designation, temp->salary, temp->phNo);
    temp->prev->next = NULL;
    free(temp);
    return head;
}

void displayNode(NodePtr node) {
    printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, PhNo: %s\n",
           node->ssn, node->name, node->dept, node->designation, node->salary, node->phNo);
}

void displayAll(NodePtr head) {
    if (!head) {
        printf("\nEmpty DLL\n");
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
        printf("\nDLL OPERATIONS\n");
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
