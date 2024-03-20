// C program to print all prime numbers within a given range
#include <stdio.h>
int main()
{
    int n1, n2, u, v, i, j, prime = 1;
    printf("Enter a range: ");
    scanf("%d%d", &n1, &n2);
    if (n1 < n2)
    {
        u = n1;
        v = n2;
    }
    else
    {
        u = n2;
        v = n1;
    }
    printf("***Prime numbers between %d & %d:\n", n1, n2);
    for (i = u; i <= v; i++)
    {
        if (i == 0 || i == 1)
        {
            continue;
        }
        else
        {
            for (j = 2; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    prime = 0;
                    break;
                }
            }
            if (prime)
            {
                printf("%d ", i);
            }
        }
        prime = 1;
    }
    return 0;
}