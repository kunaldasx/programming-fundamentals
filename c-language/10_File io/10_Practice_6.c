#include <stdio.h>

int main()
{
    FILE *ptr;
    int num;
    ptr = fopen("pr_05.txt", "r");
    fscanf(ptr, "%d", &num);
    num = 2 * num;
    ptr = fopen("pr_05.txt", "w");
    fprintf(ptr, "%d", num);
    fclose(ptr);
    return 0;
}