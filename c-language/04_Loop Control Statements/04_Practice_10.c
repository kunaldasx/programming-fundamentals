// C program to calculate the sum of numbers occuring in the multiplication table of 8
#include <stdio.h>

int main()
{
    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        sum += (8 * i);
    }
    printf("Sum: %d\n", sum);
    return 0;
}