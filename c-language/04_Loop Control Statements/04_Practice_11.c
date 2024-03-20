// C program to calculate the factorial of a given number
#include <stdio.h>

int main()
{
    int n, factorial = 1;
    printf("Enter the value of n\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    printf("The factorial of %d is %d", n, factorial);
    return 0;
}