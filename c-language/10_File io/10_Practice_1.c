#include <stdio.h>

int main()
{
    FILE *ptr;
    ptr = fopen("sample.txt", "r");
    if (ptr == NULL)
    {
        printf("This file doesnot exist\n");
    }
    else
    {
        int num, num2;
        fscanf(ptr, "%d", &num);
        fscanf(ptr, "%d", &num2);
        fclose(ptr);

        printf("The value of num is %d\n", num);
        printf("The value of num2 is %d\n", num2);
    }
    return 0;
}