// Median in a stream
#include <iostream>
#include <queue>
using namespace std;

int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void getMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap, int &median)
{
    switch (signum(maxHeap.size(), minHeap.size()))
    {

    // Both the heaps are equal (Even Number of Elements)
    case 0:
        // Insert at min heap
        if (element > median)
        {
            minHeap.push(element);
            median = minHeap.top();
        }
        // Insert at max heap
        else
        {
            maxHeap.push(element);
            median = maxHeap.top();
        }
        break;

    // max heap > min heap (Odd Number of Elements)
    case 1:
        // Insert at min heap
        if (element > median)
        {
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        // Insert at max heap
        else
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        break;

    // max heap < min heap (Odd Number of Elements)
    case -1:
        // Insert at min heap
        if (element > median)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        // Insert at max heap
        else
        {
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        break;
    }
}

// Main
vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int median = 0;

    for (int i = 0; i < n; i++)
    {
        getMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = findMedian(arr, n);
    for (auto element : ans)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}