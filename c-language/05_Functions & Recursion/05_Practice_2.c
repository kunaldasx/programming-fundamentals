// C program to calculate the area of square using library function
#include <stdio.h>
#include <math.h>

int main()
{
    int side;
    printf("Enter the value of side: ");
    scanf("%d", &side);
    printf("Area = %.2f", pow(side, 2));
    return 0;
}