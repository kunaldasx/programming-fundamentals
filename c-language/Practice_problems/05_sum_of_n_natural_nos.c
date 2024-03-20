// C program to calculate the sum of n natural numbers
#include <stdio.h>
int main()
{
    int n, sum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // for (int i = 0; i <= n; i++)
    // {
    //     sum += i; // Run in linear time
    //      // Runs in constant time
    // }
    sum = (n * n + n) / 2;
    printf("Sum: %d", sum);
    return 0;
}
