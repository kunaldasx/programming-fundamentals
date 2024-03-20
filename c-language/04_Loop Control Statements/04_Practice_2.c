// C program to print first n natural numbers using do-while loop
#include <stdio.h>

int main()
{
    int n;
    i = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    do
    {
        printf("%d\n", i + 1);
        i++;
    } while (i <= n);
    return 0;
}