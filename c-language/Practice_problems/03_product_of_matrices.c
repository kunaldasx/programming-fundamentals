// C program to multiply to matrices of different orders
#include <stdio.h>
int main()
{
    int first[10][10], second[10][10], multiply[10][10], r1, c1, r2, c2, i, j, k, sum = 0;
    printf("Enter the order of 1st matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the elements of 1st matrix\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &first[i][j]);
        }
    }
    printf("Enter the order of 2nd matrix: ");
    scanf("%d %d", &r2, &c2);
    if (r2 != c1)
    {
        printf("Matrices with entered orders can't be multiplied with each other.\n");
    }
    else
    {
        printf("Enter the elements of 2nd matrix\n");
        for (i = 0; i < r2; i++)
        {
            for (j = 0; j < c2; j++)
            {
                scanf("%d", &second[i][j]);
            }
        }
        // Multiplication of two matrices of different
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                multiply[i][j] = 0;
                for (k = 0; k < r2; k++) // r2=c1, so can choose any
                {
                    multiply[i][j] += (first[i][k] * second[k][j]);
                }
            }
        }
        printf("Product of the entered matrices\n");
        printf("********************************\n\n");
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c2; j++)
            {
                printf("%d ", multiply[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
