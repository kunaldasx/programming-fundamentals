// Find peak in a mountain array
#include <iostream>
using namespace std;

int findPeak(int arr[], int n)
{
    int si = 0;
    int ei = n - 1;
    while (si != ei)
    {
        int mid = si + (ei - si) / 2;
        if (arr[mid] < arr[mid + 1])
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
    int arr[] = {1, 3, 5, 7, 2, 0};

    cout << arr[findPeak(arr, 6)] << endl;
    return 0;
}