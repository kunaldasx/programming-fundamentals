// C program to determine  whether a character is uppercase or lowercase
#include <stdio.h>

int main()
{
    //97-122=a-z ASCII values
    char ch;
    printf("Enter a character\n");
    scanf("%c", &ch);
    if (ch <= 122 && ch >= 97)
    {
        printf("%c is lowercase\n", ch);
    }
    else
    {
        printf("%c is uppercase\n", ch);
    }
    return 0;
}