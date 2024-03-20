// C program to print all even numbers within a given range
#include <stdio.h>
void check(int l, int u)
{
    for (int i = l; i <= u; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }
    }
}
int main()
{
    int n1, n2;
    printf("Enter the lower limit: ");
    scanf("%d", &n1);
    printf("Enter the upper limit: ");
    scanf("%d", &n2);
    check(n1, n2);
    return 0;
}