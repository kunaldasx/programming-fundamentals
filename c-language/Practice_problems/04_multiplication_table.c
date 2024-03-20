// C program to print multiplication table
#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Multiplication table of %d:\n", num);
    printf("***************************\n");
    for (int i = 0; i <= 10; i++)
    {
        printf("%d X %d = %d\n", num, i, num * i);
    }
    return 0;
}