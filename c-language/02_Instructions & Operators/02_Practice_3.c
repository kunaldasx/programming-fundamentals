// C program to check whether a number is divisible by 97 or not (without using conditional instructions)
#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number:\n");
    scanf("%d", &num);
    printf("Divisibility test returns: %d\n", num % 97);
    return 0;
}