// C program to calculate the armstrong of a number

#include <stdio.h>
#include <math.h>

int main()
{
    int num, temp1, temp2, expo = 0, rem, res = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp1 = num;
    while (temp1)
    {
        temp1 = temp1 / 10;
        expo++;
    }
    temp2 = num;
    while (temp2)
    {
        rem = temp2 % 10;
        res += pow(rem, expo);
        temp2 = temp2 / 10;
    }
    if (res == num)
    {
        printf("%d is Armstrong", num);
    }
    else
    {
        printf("%d is not Armstrong", num);
    }

    return 0;
}