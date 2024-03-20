//C program to calculate the area of a rectangle
#include <stdio.h>

int main()
{
    float length, breadth;
    printf("Enter the length of the rectangle:\n");
    scanf("%f", &length);
    printf("Enter the breadth of the rectangle:\n");
    scanf("%f", &breadth);

    printf("Area of the rectangle: %f", length * breadth);
    return 0;
}