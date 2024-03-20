// C program to change the value of a variable to 10 times
#include <stdio.h>

void multiply(int *a)
{
    *a = *a * 10;
}

int main()
{
    int i = 10;
    multiply(&i);
    printf("Value of i is %d", i);
    return 0;
}