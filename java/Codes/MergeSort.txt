#include <stdio.h>

void conquer(int *arr, int si, int mid, int ei)
{
    int merged[ei - si + 1];
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;
    while (idx1 <= mid && idx2 <= ei)
    {
        if (arr[idx1] <= arr[idx2])
        {
            merged[x++] = arr[idx1++];
        }
        else
        {
            merged[x++] = arr[idx2++];
        }
    }

    while (idx1 <= mid)
    {
        merged[x++] = arr[idx1++];
    }

    while (idx2 <= ei)
    {
        merged[x++] = arr[idx2++];
    }

    for (int i = 0, j = si; i < (ei - si + 1); i++, j++)
    {
        arr[j] = merged[i];
    }
}

void divide(int *arr, int si, int ei)
{
    int mid;

    if (si >= ei)
    {
        return;
    }

    mid = si + (ei - si) / 2;
    divide(arr, si, mid);
    divide(arr, mid + 1, ei);
    conquer(arr, si, mid, ei);
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[10], size, i;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    divide(arr, 0, size - 1);

    display(arr, size);

    return 0;
}