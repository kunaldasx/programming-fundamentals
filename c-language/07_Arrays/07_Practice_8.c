#include <stdio.h>
void printTable(int *multable, int num, int n)
{
    printf("Multiplication table of %d:\n", num);
    for (int i = 0; i < n; i++)
    {
        multable[i] = num * (i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d X %d = %d\n", num, i + 1, multable[i]);
    }
    printf("***********************************************\n\n");
}

int main()
{
    int multable[3][10];
    int a, b, c;
    printf("Enter three numbers whose table is to be printed: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("\n\n");
    printTable(multable[0], a, 10);
    printTable(multable[1], b, 10);
    printTable(multable[2], c, 10);
    return 0;
}