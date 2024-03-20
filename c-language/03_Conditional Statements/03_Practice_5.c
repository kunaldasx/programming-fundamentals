// C program to check whether a entered is a leap year or not
#include <stdio.h>

int main()
{
    int year;
    printf("Enter a year\n");
    scanf("%d", &year);

    //leap year if perfectly divisible by 400
    if (year % 400 == 0)
    {
        printf("%d is a leap year\n", year);
    }
    //Not a leap year if not divisible by 400
    //but perfectly divisible by 100
    else if (year % 100 == 0)
    {
        printf("%d is not a leap year\n", year);
    }
    //Leap year if not divisible by 100
    //but perfectly divisible by 4
    else if (year % 4 == 0)
    {
        printf("%d is a leap year\n", year);
    }
    //all the other years are not leap years
    else
    {
        printf("%d is not a leap year\n", year);
    }
    return 0;
}