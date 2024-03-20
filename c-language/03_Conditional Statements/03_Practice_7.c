// Cprogram to find the maximum of 4 numbers
#include <stdio.h>

int main()
{
    int a, b, c, d;
    printf("Enter four numbers:\n");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a > b && a > c && a > d)
    {
        printf("%d is the largest number:\n", a);
    }
    else if (b > a && b > c && b > d)
    {
        printf("%d is the largest number:\n", b);
    }
    else if (c > a && c > b && c > d)
    {
        printf("%d is the largest number:\n", c);
    }
    else
    {
        printf("%d is the largest number:\n", d);
    }
    return 0;
}