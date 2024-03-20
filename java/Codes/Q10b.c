#include <stdio.h>
#include <string.h>

int main()
{
    int n = 5;
    char ch = 'A';
    int k = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            if (k % 2 == 0)
            {

                printf("%c ", (ch));
                k++;
            }
            else
            {
                printf("%c ", (ch + 32));
                k++;
            }
            ch++;
        }
        printf("\n");
    }
    return 0;
}
