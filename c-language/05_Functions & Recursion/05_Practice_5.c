// C program to convert celcius temperature into fahrenheit using user defined functions
#include <stdio.h>
float temp(float celcius);

int main()
{
    float celcius;
    printf("Enter the value of temperature in celcius:\n");
    scanf("%f", &celcius);
    printf("The value of %f degrees celcius in fahrenheit is %f\n", celcius, temp(celcius));
    return 0;
}
float temp(float celcius)
{
    float far;
    far = (celcius * 9 / 5) + 32;
    return far;
}