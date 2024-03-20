// C program to convert a decimal number to binary
#include <stdio.h>
int main()
{
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    int rem, ar[10], i = 0;
    while (n)
    {
        rem = n % 2;
        n = n / 2;
        ar[i] = rem;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", ar[j]);
    }
    return 0;
}