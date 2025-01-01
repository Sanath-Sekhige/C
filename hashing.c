#include <stdio.h>
#include <stdlib.h>
#define MAX_EMPLOYEES 10

typedef struct employee {
    int id;
    char name[20];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int hashTable[MAX_EMPLOYEES], employeeCount = 0;

int addEmployee(int hashKey, int empID) {
    FILE* file = fopen("open.txt", "a+");

    employees[hashKey].id = empID;
    printf("\nEnter employee name and salary: ");
    scanf("%s %f", employees[hashKey].name, &employees[hashKey].salary);

    fprintf(file, "%d\t%s\t%.2f\n", employees[hashKey].id, employees[hashKey].name, employees[hashKey].salary);
    fclose(file);

    return hashKey;
}

void displayHashTable() {
    printf("\nHash Table:");
    printf("\nKey\tID\tName\t\tSalary");
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (hashTable[i] != -1) {
            printf("\n%d\t%d\t%-15s\t%.2f", i, employees[i].id, employees[i].name, employees[i].salary);
        }
    }
}

void handleCollision(int hashKey, int empID) {
    int currentIndex = hashKey;

    if (employeeCount == MAX_EMPLOYEES) {
        printf("\nError: Hash table is full. Cannot add more employees.\n");
        return;
    }

    if (hashTable[hashKey] == -1) {
        hashTable[hashKey] = addEmployee(hashKey, empID);
        employeeCount++;
        displayHashTable();
    } else {
        printf("\nCollision detected at key %d. Resolving using linear probing...\n", hashKey);
        while (hashTable[currentIndex] != -1) {
            currentIndex = (currentIndex + 1) % MAX_EMPLOYEES;
        }
        hashTable[currentIndex] = addEmployee(currentIndex, empID);
        employeeCount++;
        printf("\nCollision resolved! Updated hash table:\n");
        displayHashTable();
    }
}

int main() {
    int hashKey, empID, continueInput = 1;

    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        hashTable[i] = -1;
    }

    printf("Welcome to the Employee Management System using Hashing\n");

    do {
        printf("\nEnter the employee ID (positive integer): ");
        scanf("%d", &empID);

        hashKey = empID % MAX_EMPLOYEES;
        handleCollision(hashKey, empID);

        printf("\nDo you want to continue adding employees? (1=Yes, 0=No): ");
        scanf("%d", &continueInput);
    } while (continueInput);

    printf("\nFinal Hash Table:\n");
    displayHashTable();

    printf("\nKeys in hash table: ");
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (hashTable[i] != -1) {
            printf("%d ", hashTable[i]);
        }
    }
    printf("\n");
    return 0;
}