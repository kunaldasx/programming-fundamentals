// C program to print all letters in English alphabet using a pointer.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ch;
    ch = (char *)malloc(sizeof(char));
    *ch = 'A';
    while (*ch <= 'Z')
    {
        printf("%c ", *ch);
        *ch = *ch + 1;
    }
    return 0;
}