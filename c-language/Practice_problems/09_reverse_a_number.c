// C program to reverse a number
#include <stdio.h>

int reverse(int n)
{
    int rem, rev = 0;
    while (n != 0)
    {
        rem = n % 10;         // Last digit of num
        rev = rev * 10 + rem; // Generate a number from rev with rem as last digit
        n = n / 10;
    }
    return rev;
}
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("%d", reverse(num));
    return 0;
}