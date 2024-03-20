// C program to check whether a given character is present in a string or not
#include <stdio.h>
int checkchar(char *ptr, char c)
{
    int count = 0;
    while (*ptr != '\0')
    {
        if (*ptr == c)
        {
            return 1;
        }
        ptr++;
    }
}
int main()
{
    char str[45];
    char c;
    printf("Enter a word: \n");
    fgets(str, 45, stdin);
    printf("Enter the character whose presence is to be checked: \n");
    scanf("%c", &c);

    int v = checkchar(str, c);
    if (v == 1)
    {
        printf("%c is present is the string\n", c);
    }
    else
    {
        printf("%c is not present is the string\n", c);
    }
    return 0;
}