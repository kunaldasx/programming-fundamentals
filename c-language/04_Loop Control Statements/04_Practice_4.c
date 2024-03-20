// C program to print the multiplication table of a given number
#include <stdio.h>

int main()
{
    int n;
    printf("Enter***what table you want:\n");
    scanf("%d", &n);

    printf("****Multiplication of %d****\n", n);
    for (int i = 0; i <= 10; i++)
    {
        printf("%d * %d = %d\n", n, i, n * i);
    }
    return 0;
}