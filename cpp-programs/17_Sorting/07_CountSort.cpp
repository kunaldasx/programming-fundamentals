// Count Sort
#include <iostream>
#include <climits>
using namespace std;

void countSort(int arr[], int n)
{
    int k = arr[0];
    for (int i = 1; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    int count[k + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    int ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
        ans[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
}
int main()
{
    // int n;
    // cin >> n;

    int arr[] = {1, 2, 3, 2, 4, 1, 6, 4, 3};
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    countSort(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}