// C program to print the multiplication of a given number in reverse order
#include <stdio.h>

int main()
{
    int n;
    printf("Enter***What table you want:\n");
    scanf("%d", &n);

    printf("****Multiplication table of %d*****\n", n);
    for (int i = 10; i >= 0; i--)
    {
        printf("%d * %d = %d\n", n, i, n * i);
    }

    return 0;
}