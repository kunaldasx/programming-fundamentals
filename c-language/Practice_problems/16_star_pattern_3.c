// Write a program to print the following star pattern for a generalised value of n:

//    *
//   ***
//  *****
// *******

// The above  pattern is for n=4

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (j >= n - 1 - i && j <= n - 1 + i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}