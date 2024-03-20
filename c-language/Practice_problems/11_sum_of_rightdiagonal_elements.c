// C program to calculate the sum of the lower diagonal elements of a square matrix
#include <stdio.h>
int sum_diag(int arr[][10], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i + j == size - 1)
            {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}
int main()
{
    int ar[10][10], n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the elements of the square matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }
    printf("Sum: %d", sum_diag(ar, n));
    return 0;
}