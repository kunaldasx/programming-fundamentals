// C program to calculate simple interest
#include <stdio.h>

int main()
{
    int principal, time, rate;
    printf("Enter principal:\n");
    scanf("%d", &principal);
    printf("Enter No. of years:\n");
    scanf("%d", &time);
    printf("Enter rate of interest:\n");
    scanf("%d", &rate);

    float si = principal * time * rate / 100;
    printf("Simple interest: %f\n", si);
    return 0;
}