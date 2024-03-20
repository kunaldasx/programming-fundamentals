#include <stdio.h>

int main()
{
    int i = 7;

    int *j; // pointer to an integer
    j = &i;

    int **k; // pointer to a pointer
    k = &j;

    printf("value of i: %d\n", i);
    printf("value of i: %d\n", *j);
    printf("value of i: %d\n", *(&i));
    printf("value of j: %u\n", j);
    printf("value of j: %u\n", *(&j));

    printf("Address of i: %u\n", j);
    printf("Address of i: %u\n", &i);
    printf("Address of j: %u\n", &j);

    printf("value of i: %d\n", **k);
    printf("value of j: %u\n", *k);
    printf("Address of i: %u\n", *k);

    return 0;
}