// C program to calculate the power
#include <stdio.h>

int main()
{
    int base;
    int pow;
    long long int val = 1;

    printf("Enter a number: ");
    scanf("%d", &base);

    printf("Enter the power: ");
    scanf("%d", &pow);

    for (int i = 0; i < pow; i++)
    {
        val = val * base;
    }
    printf("Power: %d", val);
    return 0;
}