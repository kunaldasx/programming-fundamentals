// C program to print the transpose of a matrix
#include <stdio.h>

int main()
{
    int source[10][10], transpose[10][10], r, c;
    printf("Enter the order of the matrix: ");
    scanf("%d %d", &r, &c);
    printf("Enter the elements the matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &source[i][j]);
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            transpose[j][i] = source[i][j];
        }
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}