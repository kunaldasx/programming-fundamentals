#include <stdio.h>
#include <string.h>

int main()
{
    char str1[34];
    char str2[34];
    char c;
    int i = 0;

    printf("Enter the content of the first string\n");
    scanf("%s", str1);

    printf("Enter the content of the second string\n");

    // while (getchar() != '\n')
    ; // Better way than using fflush(stdin);
    fflush(stdin);
    while (c != '\n')
    {
        scanf("%c", &c);
        str2[i] = c;
        i++;
    }
    str2[i - 1] = '\0';

    printf("The value of str1 is: %s\n", str1);
    printf("The value of str2 is: %s\n", str2);
    printf("strcmp for these strings return %d", strcmp(str1, str2));
    return 0;
}