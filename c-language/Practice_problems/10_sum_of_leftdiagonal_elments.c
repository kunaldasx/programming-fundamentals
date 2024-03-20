// C program to calculate the sum of the diagonal elements of a square matrix
#include <stdio.h>

int main()
{
    int ar[10][10], n, sum = 0;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum += ar[i][j];
            }
        }
    }
    printf("Sum: %d", sum);
    return 0;
}