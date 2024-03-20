// This is a program for my own version of strlen fuction from <string.h>
#include <stdio.h>
int my_strlen(char *ptr)
{
    int count = 0;
    while (*ptr != '\0')
    {
        count++;
        ptr++;
    }
    return count;
}

int main()
{
    char str[] = "Black Pink";
    printf("The length of the string is %d", my_strlen(str));
    return 0;
}