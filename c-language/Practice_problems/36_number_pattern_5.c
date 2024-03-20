#include <stdio.h>
void print_pattern(int n)
{
    int i;
    if (n == 1)
    {
        printf("%d\n", n);
        return;
    }
    else
    {
        print_pattern(n - 1);
        for (i = 1; i <= n; i++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    print_pattern(n);
    return 0;
}