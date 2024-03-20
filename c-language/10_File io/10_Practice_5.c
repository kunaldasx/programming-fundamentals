#include <stdio.h>

int main()
{
    char name1[10], name2[10];
    float sal1, sal2;
    printf("Enter the name of the first employee: ");
    scanf("%s", name1);
    printf("Enter the salary of the first employee: ");
    scanf("%f", &sal1);

    printf("Enter the name of the second employee: ");
    scanf("%s", name2);
    printf("Enter the salary of the second employee: ");
    scanf("%f", &sal2);

    FILE *ptr;
    ptr = fopen("pr_04.txt", "w");

    fprintf(ptr, "Name: %s\nSalary: %.3f\n\n", name1, sal1);
    fprintf(ptr, "Name: %s\nSalary: %.3f\n", name2, sal2);
    fclose(ptr);

    return 0;
}