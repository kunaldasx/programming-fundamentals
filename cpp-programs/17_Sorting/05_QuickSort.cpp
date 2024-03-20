// Quick Sort
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int idx = low - 1;

    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            idx++;
            // swap
            int temp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = temp;
        }
    }

    idx++;
    // swap with pivot
    int temp = arr[idx];
    arr[idx] = arr[high];
    arr[high] = temp;

    return idx;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}