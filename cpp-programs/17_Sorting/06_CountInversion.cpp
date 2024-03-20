// Count Inversions in an array using merge sort algo
#include <iostream>
using namespace std;

long long merge(int arr[], int si, int mid, int ei)
{
    long long inv = 0;
    int idx1 = si;
    int idx2 = mid + 1;
    int x = 0;
    int merged[ei - si + 1];

    while (idx1 <= mid && idx2 <= ei)
    {
        if (arr[idx1] <= arr[idx2])
        {
            merged[x++] = arr[idx1++];
        }
        else
        {
            merged[x++] = arr[idx2++];
            inv += (mid - idx1 + 1); // All the elements after idx1 till mid will be greater than idx2
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
    return inv;
}

long long mergeSort(int arr[], int si, int ei)
{
    long long inv = 0;
    if (si < ei)
    {
        int mid = (si + ei) / 2;
        inv += mergeSort(arr, si, mid);
        inv += mergeSort(arr, mid + 1, ei);
        inv += merge(arr, si, mid, ei);
    }
    return inv;
}
int main()
{
    int arr[] = {3, 5, 6, 9, 1, 2, 7, 8};

    cout << mergeSort(arr, 0, 7) << endl;

    return 0;
}