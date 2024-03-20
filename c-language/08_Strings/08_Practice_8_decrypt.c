#include <stdio.h>
void decrypt(char *ptr)
{
    while (*ptr != '\0')
    {
        *ptr = *ptr - 1;
        ptr++;
    }
}
int main()
{
    char str[] = "Cmbdl!Qjol";
    decrypt(str);
    printf("Decrypted string is: %s", str);
    return 0;
}