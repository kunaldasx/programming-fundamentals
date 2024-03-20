#include <stdio.h>

struct employee
{

    int code;
    float salary;
    char name[10];
};

int main()
{
    struct employee e1, e2, e3;
    printf("Enter the code of the first employee: ");
    scanf("%d", &e1.code);
    printf("Enter the salary of the first employee: ");
    scanf("%f", &e1.salary);
    printf("Enter the name of the frist employee: ");
    scanf("%s", e1.name);

    printf("\nEnter the code of the second employee: ");
    scanf("%d", &e2.code);
    printf("Enter the salary of the second employee: ");
    scanf("%f", &e2.salary);
    printf("Enter the name of the second employee: ");
    scanf("%s", e2.name);

    printf("\nEnter the code of the third employee: ");
    scanf("%d", &e3.code);
    printf("Enter the salary of the third employee: ");
    scanf("%f", &e3.salary);
    printf("Enter the name of the third employee: ");
    scanf("%s", e3.name);

    printf("For the first employee:\n");
    printf("Name: %s\n", e1.name);
    printf("Code: %d\n", e1.code);
    printf("Salary: %.3f\n", e1.salary);

    printf("For the second employee:\n");
    printf("Name: %s\n", e2.name);
    printf("Code: %d\n", e2.code);
    printf("Salary: %.3f\n", e2.salary);

    printf("For the third employee:\n");
    printf("Name: %s\n", e3.name);
    printf("Code: %d\n", e3.code);
    printf("Salary: %.3f", e3.salary);

    return 0;
}