// This is a program for my own version of strcpy function from <string.h>
#include <stdio.h>
void my_strcpy(char *source, char *target)
{
    int i;
    for (i = 0; i < 45; i++)
    {
        source[i] = target[i];
    }
    target[i] = '\0';
}

int main()
{
    char source[45];
    printf("Enter a word: \n");
    gets(source);
    char target[45];
    my_strcpy(target, source);
    printf("Now the  content of source are: %s\n", source);
    printf("Now the  content of target are: %s\n", target);
    return 0;
}