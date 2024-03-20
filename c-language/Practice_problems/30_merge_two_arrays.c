// C program to merge two arrays and sort them in ascending order
#include <stdio.h>
void merge_asc(int res[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (res[i] < res[j])
            {
                temp = res[i];
                res[i] = res[j];
                res[j] = temp;
            }
        }
    }
    printf("Ascending order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", res[i]);
    }
}
void merge_desc(int res[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (res[i] > res[j])
            {
                temp = res[i];
                res[i] = res[j];
                res[j] = temp;
            }
        }
    }
    printf("Descending order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", res[i]);
    }
}
int main()
{
    int first[10], second[10], res[20], n1, n2, i;
    printf("Enter the size of 1st array: ");
    scanf("%d", &n1);
    printf("Enter the elements of 1st array:\n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &first[i]);
    }
    printf("Enter the size of 2nd array: ");
    scanf("%d", &n2);
    printf("Enter the elements of 2nd array:\n");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &second[i]);
    }
    for (i = 0; i < n1; i++)
    {
        res[i] = first[i];
        res[i + n1] = second[i];
    }
    printf("The elements of the new array:\n");
    for (i = 0; i < (n1 + n2); i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    merge_asc(res, (n1 + n2));
    printf("\n");
    merge_desc(res, (n1 + n2));
    return 0;
}