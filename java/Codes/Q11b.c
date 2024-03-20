// C program to find the common elements in an array
#include <stdio.h>

int main()
{
    int ar[10], size, i, j;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &ar[i]);
    }
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (ar[j] == ar[i])
            {
                printf("%d ", ar[i]);
            }
        }
    }
    return 0;
}
