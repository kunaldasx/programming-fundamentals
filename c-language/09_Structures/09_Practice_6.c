#include <stdio.h>
#include <string.h>

struct employee
{
    int code;
    float salary;
    char name[10];
};

int main()
{
    struct employee e1, e2;
    struct employee *ptr;
    ptr = &e1;
    // For the first employee
    ptr->code = 100;
    ptr->salary = 345.000;
    strcpy(ptr->name, "Black Pink");
    printf("For the 1st employee:\n");
    printf("Code: %d\n", ptr->code);
    printf("Salary: %.3f\n", ptr->salary);
    printf("Name: %s\n", ptr->name);

    // For the second employee
    e2.code = 101;
    e2.salary = 456.043;
    strcpy(e2.name, "Twice");
    printf("\nFor the 2nd employee:\n");
    printf("Code: %d\n", e2.code);
    printf("Salary: %.3f\n", e2.salary);
    printf("Name: %s\n", e2.name);
    return 0;
}