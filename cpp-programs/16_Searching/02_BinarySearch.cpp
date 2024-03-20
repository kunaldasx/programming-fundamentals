// Binary Search
#include <iostream>
using namespace std;

void binarySearch(int arr[], int si, int ei, int key)
{
    if (si > ei)
    {
        cout << "The key is not present in the array" << endl;
        return;
    }

    int mid = (si + ei) / 2;
    if (arr[mid] == key)
    {
        cout << "The number is present at index: " << mid << endl;
        return;
    }
    if (arr[mid] > key)
    {
        binarySearch(arr, si, mid - 1, key);
    }
    if (arr[mid] < key)
    {
        binarySearch(arr, mid + 1, ei, key);
    }
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

    int key;
    cin >> key;
    binarySearch(arr, 0, n - 1, key);

    return 0;
}
