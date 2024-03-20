// C program to calculate the four basic arithmetic operations
#include <stdio.h>
float calc(float a, float b, int ch)
{
    float res;
    switch (ch)
    {
    case 1:
        res = a + b;
        break;
    case 2:
        res = a - b;
        break;
    case 3:
        res = a * b;
        break;
    case 4:
        res = a / b;
        break;
    default:
        printf("Please Enter Valid Information");
    }
    return res;
}
int main()
{
    int ch;
    float num1, num2, res;
    printf("Select a Choice\nPress 1 for Addition\nPress 2 for Subtraction\nPress 3 for Multiplication\nPress 4 for Division\n");
    scanf("%d", &ch);
    printf("Enter Two Numbers \n");
    scanf("%f%f", &num1, &num2);
    printf("Result=%.2f", calc(num1, num2, ch));
    return 0;
}