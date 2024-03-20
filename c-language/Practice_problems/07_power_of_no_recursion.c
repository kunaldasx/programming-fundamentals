// C program to calculate the power of a number using recursion
#include <stdio.h>
float power(float base, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    else if (pow > 0)
    {
        return base * power(base, pow - 1);
    }
    else
    {
        return 1 / power(base, -pow);
    }
}
int main()
{
    float base, res;
    int pow;
    printf("Enter the base: ");
    scanf("%f", &base);
    printf("Enter the power: ");
    scanf("%d", &pow);

    printf("Result: %.2f", power(base, pow));
    return 0;
}