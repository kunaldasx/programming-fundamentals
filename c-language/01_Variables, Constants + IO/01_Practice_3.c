// C program to convert celcius temperature to fahrenheit
#include <stdio.h>

int main()
{
    float celcius, fahrenheit;
    printf("Enter a temperature in degrees centigrade\n");
    scanf("%f", &celcius);

    fahrenheit = (celcius * 9 / 5) + 32;
    printf("Value of the temperature in fahrenheit is %f", fahrenheit);
    return 0;
}