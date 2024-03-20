// C program to calculate the sum of first n natural numbers using rucursive function
#include <stdio.h>
int sum(int n);

int main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    printf("Sum: %d", sum(n));
    return 0;
}
int sum(int n)
{
    int result;
    if (n != 0)
    {
        result = n + sum(n - 1);
        return result;
    }
    else
    {
        return n;
    }
}