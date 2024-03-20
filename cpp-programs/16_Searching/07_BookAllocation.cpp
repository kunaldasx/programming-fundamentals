// Book Allocation Problem
#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(int arr[], int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int si = 0;
    int ei = sum;
    int ans = -1;

    while (si <= ei)
    {
        int mid = si + (ei - si) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    cout << allocateBooks(arr, 4, 2) << endl;
    return 0;
}