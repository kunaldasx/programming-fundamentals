// Algorithm for Heap Sort
#include <iostream>
using namespace std;

// Converts an array into a heap
// Time --- O(logN)
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

// Heap Sort
// Time --- O(NlogN)
void heapSort(int arr[], int n)
{
    int t = n;

    while (t > 1)
    {
        // Step 1: Swap the first element with the last
        swap(arr[1], arr[t]);
        t--;

        // Step 2: Heapify the new first element
        heapify(arr, t, 1);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    heapSort(arr, n);

    cout << "Printing the Sorted Heap." << endl;
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}