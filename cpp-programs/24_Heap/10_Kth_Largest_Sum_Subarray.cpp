// Kth largest sum Subarray
#include <iostream>
#include <queue>
using namespace std;

int kthLargestSumSubarray(vector<int> arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter K: ";
    cin >> k;

    cout << "Kth Largest Sum Subarray = " << kthLargestSumSubarray(arr, k) << endl;
    return 0;
}