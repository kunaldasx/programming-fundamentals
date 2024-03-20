// C program to print the following star pattern for a generalised value of n:
// for n=3
// *
// ***
// *****
// 1-1
// 2-3
// 3-5
// (2n-1)
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 2 * i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}