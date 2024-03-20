// C program to calculate the factorial of a number using recursion
#include <stdio.h>

int factorial(int x)
{
    int f;
    if (x == 0 || x == 1)
    {
        return 1;
    }
    else
    {
        f = x * factorial(x - 1);
        return f;
    }
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Factorial of %d = %d\n", n, factorial(n));
    return 0;
}