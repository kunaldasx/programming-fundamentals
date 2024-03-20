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
void countingSort(int arr[], int size, int pos)
{
    int count[size];
    int newArr[size], i;
    for (i = 0; i < size; i++)
    {
        count[i] = 0;
    }

    // Filling the counter array
    for (i = 0; i < size; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }

    // Updating the counter array
    for (i = 1; i < size; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    // Filling the new sorted array
    for (i = size - 1; i >= 0; i--)
    {
        newArr[--count[(arr[i] / pos) % 10]] = arr[i];
    }

    // Copying the new array to the main array
    for (i = 0; i < size; i++)
    {
        arr[i] = newArr[i];
    }
}

void radixSort(int arr[], int size)
{
    int pos;
    int max = findMax(arr, size);
    for (pos = 1; max / pos > 0; pos *= 10)
    {
        countingSort(arr, size, pos);
    }
}

int main()
{
    int i;
    int arr[45] = {432, 8, 530, 90, 88, 231, 11, 45, 677, 199};
    // printf("Enter size of array: ");
    // scanf("%d", &size);
    radixSort(arr, 10);

    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}