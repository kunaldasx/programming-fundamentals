// C program to multiply to matrices of same orders
#include <stdio.h>
int main()
{
    int first[10][10], second[10][10], multiply[10][10], r, c, i, j, k;
    printf("Enter the order of both matrix: ");
    scanf("%d %d", &r, &c);
    printf("Enter the elements of 1st matrix\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &first[i][j]);
        }
    }

    printf("Enter the elements of 2nd matrix\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &second[i][j]);
        }
    }
    // Multiplication of two matrices of different
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            multiply[i][j] = 0;
            for (k = 0; k < c; k++) // r2=c1, so can choose any
            {
                multiply[i][j] += first[i][k] * second[k][j];
            }
        }
    }
    printf("Product of the entered matrices\n");
    printf("********************************\n\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", multiply[i][j]);
        }
        printf("\n");
    }

    return 0;
}
