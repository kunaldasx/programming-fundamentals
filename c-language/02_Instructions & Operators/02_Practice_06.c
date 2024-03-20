// C program to check if a given character is a digit or not.
#include <stdio.h>

int main()
{
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);
    if (ch >= '0' && ch <= '9')
    {
        printf("It is a digit");
    }
    else
    {
        printf("It is not a digit");
    }
    return 0;
}