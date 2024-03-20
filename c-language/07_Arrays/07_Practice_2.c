// C program to demonstrate all the operations that can be performed on a pointer
#include <stdio.h>

int main()
{
    // Addition of a number to a pointer
    int a = 12;
    int *ptr_1 = &a;
    printf("The value of ptr_1 is %u\n", ptr_1);
    ptr_1++;
    // ptr_1 = ptr_1 + 1;
    printf("The value of ptr_1 is %u\n", ptr_1);

    // Subtraction of a number from a pointer
    int b = 14;
    int *ptr_2 = &b;
    printf("The value of ptr_2 is %u\n", ptr_2);
    ptr_2--;
    printf("The value of ptr_2 is %u\n", ptr_2);

    // Subtraction of one pointer from another
    int i = 1.7;
    int *ptr1, *ptr2;
    ptr1 = &i;
    ptr2 = &i;

    ptr2 = ptr2 + 3;

    int z;
    z = ptr2 - ptr1;
    printf("The value of z is %u\n", z);
    return 0;
}