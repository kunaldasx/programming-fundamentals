#include <stdio.h>

void printAdd(int a)
{
    printf("Address of a is %u\n", &a);
}

int main()
{
    int i = 4;
    printf("Value of i is %d\n", i);
    printAdd(i);
    printf("Address of i is %u\n", &i);
    return 0;
}