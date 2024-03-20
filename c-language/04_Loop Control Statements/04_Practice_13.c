// C program to check if a given number is prime
#include <stdio.h>

int main()
{
    int num, prime = 1;
    printf("Enter a number:\n");
    scanf("%d", &num);

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            prime = 0;
            break;
        }
    }
    if (num == 1)
    {
        printf("1 is neither prime nor composite:\n");
    }
    else if (prime)
    {
        printf("%d is prime:\n", num);
    }
    else
    {
        printf("%d is non prime:\n", num);
    }
    return 0;
}