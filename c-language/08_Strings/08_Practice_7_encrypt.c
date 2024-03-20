#include <stdio.h>
void encrypt(char *ptr)
{
    while (*ptr != '\0')
    {
        *ptr = *ptr + 1;
        ptr++;
    }
}
int main()
{
    char str[45];
    printf("Enter the words that has to be encrypted: \n");
    gets(str);
    encrypt(str);
    printf("Encrypted string is: %s", str);
    return 0;
}