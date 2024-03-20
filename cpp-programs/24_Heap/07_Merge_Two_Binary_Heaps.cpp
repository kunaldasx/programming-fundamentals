// Merge two binary max heaps
#include <iostream>
#include <vector>
using namespace std;

// Converts an array into a max heap
// Time --- O(logN)
void heapify(vector<int> &merged, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && merged[largest] < merged[left])
    {
        largest = left;
    }
    if (right < n && merged[largest] < merged[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(merged[largest], merged[i]);
        heapify(merged, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &h1, vector<int> &h2)
{
    // Step 1: Merge Both vectors
    vector<int> merged;

    for (auto i : h1)
    {
        merged.push_back(i);
    }
    for (auto i : h2)
    {
        merged.push_back(i);
    }

    // Step 2: Build heap using merged array
    int n = merged.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(merged, n, i);
    }
    return merged;
}

int main()
{
    vector<int> h1;
    cout << "Enter data for 1st vector:" << endl;
    int i;
    cin >> i;
    while (i != -1)
    {
        h1.push_back(i);
        cin >> i;
    }

    vector<int> h2;
    cout << "Enter data for 2nd vector:" << endl;
    cin >> i;
    while (i != -1)
    {
        h2.push_back(i);
        cin >> i;
    }

    vector<int> merged = mergeHeaps(h1, h2);
    for (auto i : merged)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}