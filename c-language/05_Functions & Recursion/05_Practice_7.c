// C progarm to calculate nth element of fibonacci series using recursion
#include <stdio.h>
int fib(int n);

int main()
{
    int n;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    printf("The value of the nth term is %d\n", fib(n));
    return 0;
}
int fib(int n)
{
    int result;
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        result = fib(n - 1) + fib(n - 2); // fib(n)=fib(n-1)+fib(n-2)
        return result;
    }
}