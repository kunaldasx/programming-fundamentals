// Kth Smallest element in an array
#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int size, int k)
{
    priority_queue<int> pq;

    // Step 1: Create a heap with the first k elements of the array
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // Step 2: Compare the remaining elements of the array with the top of the queue
    // if it's smaller -> pop the queue and push the element
    for (int i = k; i < size; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // Step 3: Now the top of the queue is the kth smallest element of the array
    return pq.top();
}

int main()
{
    int *arr;
    int n;
    cout << "Enter the size: ";
    cin >> n;

    arr = new int(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    cout << k << "th smallest element = " << kthSmallest(arr, n, k) << endl;
    return 0;
}