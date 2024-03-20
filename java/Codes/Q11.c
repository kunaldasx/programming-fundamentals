#include <stdio.h>

int main()
{
    int ar[10], size, sum = 0, sum1 = 0;
    printf("Enter size");
    scanf("%d", &size);
    printf("Enter a number:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ar[i]);
    }
    int mid = (size / 2);
    for (int i = mid; i < size; i++)
    {
        sum += ar[i];
    }
    for (int i = 0; i < mid; i++)
    {
        sum1 += ar[i];
    }

    if (sum == sum1)
    {
        printf("You win");
    }
    else
    {
        printf("Better luck next time");
    }

    return 0;
}