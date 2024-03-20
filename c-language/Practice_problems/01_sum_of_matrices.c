// C program to add two matrices
#include <stdio.h>
int main()
{
    int first[10][10], second[10][10], sum[10][10], r, c, i, j;
    printf("Enter the order of both matries(Order must be same for both): ");
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
    // Adding two matrices
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            sum[i][j] = first[i][j] + second[i][j];
        }
    }
    // Printing the resultant matrix
    printf("Sum of the entered matrices:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}