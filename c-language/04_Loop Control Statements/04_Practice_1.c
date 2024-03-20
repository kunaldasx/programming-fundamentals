// c program to print natural numbers from 10 to 20 when initial loop counter i is initialised to 0
#include <stdio.h>

int main()
{
    int i = 0;
    while (i <= 20)
    {
        if (i >= 10)
        {
            printf("The value of i is %d\n", i);
        }
        i++;
    }
    return 0;
}