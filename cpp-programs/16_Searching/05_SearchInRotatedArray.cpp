// Search in a roatated and sorted array
#include <iostream>
using namespace std;

int getPivot(int arr[], int n)
{
    int si = 0;
    int ei = n - 1;

    while (si < ei)
    {
        int mid = si + (ei - si) / 2;
        if (arr[mid] > arr[0])
        {
            si = mid + 1;
        }
        else
        {
            ei = mid;
        }
    }
    return si;
}

int binarySearch(int arr[], int si, int ei, int k)
{
    while (si <= ei)
    {
        int mid = si + (ei - si) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] > k)
        {
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {7, 9, 10, 1, 2, 3};
    int k = 2;
    int pivot = getPivot(arr, 6);

    if (k >= arr[pivot] && k <= arr[6 - 1])
    {
        cout << binarySearch(arr, pivot, 6 - 1, k) << endl;
    }
    else
    {
        cout << binarySearch(arr, 0, pivot - 1, k) << endl;
    }
    return 0;
}