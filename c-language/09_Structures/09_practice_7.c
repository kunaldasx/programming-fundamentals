#include <stdio.h>

typedef struct complex
{
    float real;
    float img;
} comp;

int main()
{
    comp c1;
    c1.real = 23;
    c1.img = 45;

    printf("The real part of num is %f\n", c1.real);
    printf("The imaginary part of num is %f\n", c1.img);
    return 0;
}