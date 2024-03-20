#include <stdio.h>

int main()
{
    FILE *ptr;
    ptr = fopen("pr_01.txt", "r");
    int num1, num2, num3;
    fscanf(ptr, "%d %d %d", &num1, &num2, &num3);
    printf("The value of first integer is %d\n", num1);
    printf("The value of second integer is %d\n", num2);
    printf("The value of third integer is %d\n", num3);
    fclose(ptr);
    return 0;
}