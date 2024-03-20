#include <stdio.h>

int main()
{
    FILE *ptr;
    int num;
    printf("Enter the integer whose table you need: ");
    scanf("%d", &num);
    ptr = fopen("table.txt", "w");
    for (int i = 0; i <= 10; i++)
    {
        fprintf(ptr, "%d X %d = %d\n", num, i, num * i);
    }
    fclose(ptr);
    printf("Table generated successfully for %d to table.txt", num);
    return 0;
}