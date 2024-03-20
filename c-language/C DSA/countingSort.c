#include <stdio.h>

int findMax(int arr[], int size)
{
    int max = arr[0], i;
    for (i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int arr[], int size)
{
    int key = findMax(arr, size);
    int count[key + 1];
    int newArr[size], i;
    for (i = 0; i < key; i++)
    {
        count[i] = 0;
    }

    // Filling the counter array
    for (i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    // Updating the counter array
    for (i = 1; i <= key; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    // Filling the new sorted array
    for (i = size - 1; i >= 0; i--)
    {
        newArr[--count[arr[i]]] = arr[i];
    }

    // Copying the new array to the main array
    for (i = 0; i < size; i++)
    {
        arr[i] = newArr[i];
    }
}

int main()
{
    int i;
    int arr[45] = {9, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};
    // printf("Enter size of array: ");
    // scanf("%d", &size);
    countingSort(arr, 17);

    for (i = 0; i < 17; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}