// C program to check if a number is palindrome
#include <stdio.h>

int main()
{
    int num, temp, rem, rev;
    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;
    while (num)
    {
        rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
    }
    if (rev == temp)
    {
        printf("%d is a palindrome", temp);
    }
    else
    {
        printf("%d is not a palindrome", temp);
    }
    return 0;
}