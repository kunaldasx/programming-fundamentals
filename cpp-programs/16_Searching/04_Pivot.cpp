// Find pivot in a rotated array using binary search
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

int main()
{
    int arr[] = {7, 9, 10, 1, 2, 3};

    cout << getPivot(arr, 6) << endl;
    return 0;
}