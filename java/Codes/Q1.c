#include <stdio.h>
#include <string.h>

int main()
{
    char str[45];
    int flag = 0;
    printf("Enter a string: ");
    gets(str);
    for (int i = 0; i < strlen(str) / 2; i++)
    {
        if (str[i] == str[strlen(str) - i])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("Is Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }

    return 0;
}