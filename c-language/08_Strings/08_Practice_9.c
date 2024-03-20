// A C program to count the occurances of a given character in a string
#include <stdio.h>
int occurances(char *ptr, char c)
{
    int count = 0;
    while (*ptr != '\0')
    {
        if (*ptr == c)
        {
            count++;
        }
        ptr++;
    }
    return count;
}
int main()
{
    char str[45];
    char c;
    printf("Enter a word: \n");
    fgets(str, 45, stdin);
    printf("Enter the character whose occurance is to be checked: \n");
    scanf("%c", &c);

    printf("Occurances of %c is: %d", c, occurances(str, c));
    return 0;
}