// C program to calculate the sum and average of two numbers using a function
#include <stdio.h>

void SumAndAvg(int a, int b, int *sum, float *avg)
{
    *sum = a + b;
    *avg = (float)(*sum) / 2;
}

int main()
{
    int i = 3, j = 6, sum;
    float avg;
    SumAndAvg(i, j, &sum, &avg);
    printf("The value of sum is %d\n", sum);
    printf("The value of average is %f\n", avg);

    return 0;
}