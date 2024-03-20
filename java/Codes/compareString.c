// Compare two each character of two strings, if they are equal then add G and if unequal then add B in a
// third string and print the output
#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, t;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        printf("Enter the string: ");
        char T[10], S[10], M[10] = "";
        scanf("%s%s", &T, &S);
        for (j = 0; j < 5; j++)
        {
            if (T[j] == S[j])
            {
                strcat(M, "G");
            }
            else
            {
                strcat(M, "B");
            }
        }
        puts(M);
    }
    return 0;
}