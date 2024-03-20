// C program to find the largests and the smallest number in an array
#include <stdio.h>
int returnMax(int array[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
int returnMin(int array[], int n)
{
    int min = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}
int main()
{
    int arr[10], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // max = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > max)
    //     {
    //         max = arr[i];
    //     }
    // }
    // min = arr[0];
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] < min)
    //     {
    //         min = arr[i];
    //     }
    // }
    printf("The largest number of the array: %d\n", returnMax(arr, n));
    printf("The smallest number of the array: %d\n", returnMin(arr, n));
    return 0;
}