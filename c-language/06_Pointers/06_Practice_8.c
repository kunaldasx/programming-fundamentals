// C program to verify that call by value doesn't change the value of the said variable
#include <stdio.h>

void change(int a)
{
    a = a * 10;
}

int main()
{
    int i = 4;
    change(i);
    printf("The value of the variable i is %d\n", i);

    return 0;
}