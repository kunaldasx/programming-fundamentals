// C program to convert all lowercase characters to uppercase in a string.
#include <stdio.h>
#include <string.h>

int main()
{
    char str[45];
    int i = 0;
    printf("Enter a string: ");
    fgets(str, 45, stdin);
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        i++;
    }
    printf("New String: ");
    puts(str);
    return 0;
}