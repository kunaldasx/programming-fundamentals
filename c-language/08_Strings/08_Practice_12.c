// C program to find the highest frequency characters in a string.
#include <stdio.h>
#include <string.h>

int main()
{
    char str[45], res;
    int count = 0, max = 0;
    printf("Enter a string: ");
    fgets(str, 45, stdin);

    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                count++;
            }
        }
        if (count > max)
        {
            max = count;
            res = str[i];
        }
        count = 0;
    }
    printf("Highest frequency character: %c (%d times)", res, max);
    return 0;
}