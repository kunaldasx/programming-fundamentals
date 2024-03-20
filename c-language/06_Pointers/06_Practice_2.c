#include <stdio.h>
void wrong_swap(int x, int y);
void swap(int *x, int *y);

int main()
{
    int a = 3, b = 4;
    printf("The value of a nad b before swap is %d and %d\n", a, b);
    // wrong_ swap(a, b); will not work due to call by value

    swap(&a, &b); // will work due to call by reference
    printf("The value of a and b after swap is %d and %d\n", a, b);

    return 0;
}
void wrong_swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}