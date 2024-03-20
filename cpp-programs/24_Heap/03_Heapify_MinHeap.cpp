// // Make a Min heap from a given list of elements
#include <iostream>
using namespace std;

// Converts an array into a min heap
// Time --- O(logN)
void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1; // Since 0 based indexing is applied
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left]) // Since 0 based indexing is applied
    {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2 - 1; i >= 0; i--) // Since 0 based indexing is applied
    {
        heapify(arr, n, i);
    }

    cout << "Printing the Heap." << endl;
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}