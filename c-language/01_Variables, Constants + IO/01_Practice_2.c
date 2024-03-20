// C program to calculate the area of a circle
#include <stdio.h>

int main()
{
    float radius;
    printf("Enter the radius of the circle:\n");
    scanf("%f", &radius);
    printf("Area of the circle: %f\n", 3.14 * radius * radius);

    // c program modified to calculate the volume of a cylinder
    float height;
    printf("Enter the height of the cylinder:\n");
    scanf("%f", &height);
    printf("Area of the cylinder: %f\n", 3.14 * radius * radius * height);
    return 0;
}