// C program to insert an element at a particular position in an array.
#include <stdio.h>

int main()
{
    int arr[10], size, num, pos;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be inserted in the array: ");
    scanf("%d", &num);
    printf("Enter the position at which the number is to be inserted: ");
    scanf("%d", &pos);

    for (int i = size; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = num;
    for (int i = 0; i <= size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}