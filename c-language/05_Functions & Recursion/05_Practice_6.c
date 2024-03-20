// C program to calculate the force of atttraction on a body exerted by earth
#include <stdio.h>
float force(float mass);

int main()
{
    float mass;
    printf("Enter the value of mass in kgs:\n");
    scanf("%f", &mass);
    printf("The force of attraction is %.2f N\n", force(mass));
    return 0;
}
float force(float mass)
{
    float result;
    result = mass * 9.8;
    return result;
}