#include <stdio.h>
#define MAX_EMPLOYEES 10

typedef struct {
    int id;
    char name[20];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int hashTable[MAX_EMPLOYEES], employeeCount = 0;

void initializeHashTable() {
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        hashTable[i] = -1;
    }
}

void displayHashTable() {
    printf("\nHash Table:\nKey\tID\tName\t\tSalary\n");
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (hashTable[i] != -1) {
            printf("%d\t%d\t%-15s\t%.2f\n", i, employees[i].id, employees[i].name, employees[i].salary);
        }
    }
}

void addEmployee(int index, int empID) {
    printf("\nEnter Employee Name: ");
    scanf("%s", employees[index].name);
    printf("\nEnter Employee '%s' Salary: ");
    scanf("%f", &employees[index].salary);
    employees[index].id = empID;

    FILE *file = fopen("open.txt", "a+");
    fprintf(file, "%d\t%s\t%.2f\n", empID, employees[index].name, employees[index].salary);
    fclose(file);

    hashTable[index] = empID;
    employeeCount++;
    displayHashTable();
}

void handleCollision(int hashKey, int empID) {
    if (employeeCount == MAX_EMPLOYEES) {
        printf("Error: Hash table is full.\n");
        return;
    }

    int index = hashKey;
    while (hashTable[index] != -1) {
        index = (index + 1) % MAX_EMPLOYEES;
    }
    addEmployee(index, empID);
}

int main() {
    int empID, continueInput;

    initializeHashTable();
    printf("Employee Management System using Hashing\n");

    do {
        printf("\nEnter the employee ID (positive integer): ");
        scanf("%d", &empID);

        int hashKey = empID % MAX_EMPLOYEES;
        if (hashTable[hashKey] == -1) {
            addEmployee(hashKey, empID);
        } else {
            printf("Collision at key %d. Resolving...\n", hashKey);
            handleCollision(hashKey, empID);
        }

        printf("Continue adding employees? (1=Yes, 0=No): ");
        scanf("%d", &continueInput);
    } while (continueInput);

    printf("\nFinal Hash Table:\n");
    displayHashTable();

    return 0;
}
