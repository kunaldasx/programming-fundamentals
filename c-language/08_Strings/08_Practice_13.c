// C program to remove blank spaces from a string.
#include <stdio.h>
#include <string.h>

int main()
{
    char str[45];
    printf("Enter a string: ");
    fgets(str, 45, stdin);

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            for (int j = i; j < strlen(str); j++)
            {
                str[j] = str[j + 1];
            }
        }
    }
    puts(str);
    return 0;
}