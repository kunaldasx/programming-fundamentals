// C program to calculate the average of three numbers
#include <stdio.h>
float average(int a, int b, int c);

int main()
{
    int a, b, c;
    printf("Enter three numbers:\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("The average of %d, %d & %d is %f", a, b, c, average(a, b, c));
    return 0;
}
float average(int a, int b, int c)
{
    float result;
    result = (float)(a + b + c) / 3;
    return result;
}