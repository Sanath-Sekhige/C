#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

typedef Node* NodePtr;

NodePtr createNode(int coeff, int exp) {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

NodePtr insertRear(NodePtr head, int coeff, int exp) {
    NodePtr newNode = createNode(coeff, exp);

    if (!head) return newNode;

    NodePtr temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void display(NodePtr head) {
    if (!head) {
        printf("Polynomial is empty.\n");
        return;
    }

    NodePtr temp = head;
    while (temp) {
        if (temp->coeff > 0 && temp != head) {
            printf(" + ");
        }
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

NodePtr addPolynomials(NodePtr poly1, NodePtr poly2) {
    NodePtr result = NULL;
    while (poly1 || poly2) {
        if (poly1 && (!poly2 || poly1->exp > poly2->exp)) {
            result = insertRear(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly2 && (!poly1 || poly1->exp < poly2->exp)) {
            result = insertRear(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int coeff = poly1->coeff + poly2->coeff;
            if (coeff != 0) {
                result = insertRear(result, coeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    return result;
}

int main() {
    NodePtr poly1 = NULL, poly2 = NULL, result = NULL;
    int choice, coeff, exp;

    printf("Enter terms for the first polynomial:\n");
    do {
        printf("Enter coefficient: ");
        scanf("%d", &coeff);
        printf("Enter exponent: ");
        scanf("%d", &exp);
        poly1 = insertRear(poly1, coeff, exp);

        printf("Do you want to add more terms to the first polynomial? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice);

    printf("\nEnter terms for the second polynomial:\n");
    do {
        printf("Enter coefficient: ");
        scanf("%d", &coeff);
        printf("Enter exponent: ");
        scanf("%d", &exp);
        poly2 = insertRear(poly2, coeff, exp);

        printf("Do you want to add more terms to the second polynomial? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
    } while (choice);

    printf("\nFirst Polynomial: ");
    display(poly1);
    printf("Second Polynomial: ");
    display(poly2);

    result = addPolynomials(poly1, poly2);

    printf("\nResultant Polynomial after addition: ");
    display(result);

    return 0;
}
