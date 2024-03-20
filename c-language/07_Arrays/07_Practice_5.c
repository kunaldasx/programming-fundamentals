// C program to store multiplication table and print it
#include <stdio.h>

int main()
{
    int multi[10];
    int n;
    printf("Enter what table you want:\n");
    scanf("%d", &n);
    for (int i = 0; i < 10; i++)
    {
        multi[i] = n * (i + 1);
    }
    printf("The multiplication table of %d is:\n", n);
    for (int i = 0; i < 10; i++)
    {
        printf("%d * %d = %d\n", n, i + 1, multi[i]);
    }
    return 0;
}