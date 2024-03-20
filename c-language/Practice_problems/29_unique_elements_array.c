// C program to find the unique elements in an array
#include <stdio.h>

int main()
{
    int ar[10], size, i, j, flag = 1;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &ar[i]);
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i != j)
            {
                if (ar[j] == ar[i])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
        {
            printf("%d ", ar[i]);
        }
        flag = 1;
    }
    return 0;
}
