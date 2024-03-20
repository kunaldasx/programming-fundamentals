// Minimum cost of ropes (Connect the numbers with minimum value until only one number is left)
#include <iostream>
#include <queue>
using namespace std;

// Time --- O(NlogN)
// Space --- O(N)
int minCost(int arr[], int n)
{
    // Create a min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int cost = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int sum = a + b;
        cost += sum;

        pq.push(sum);
    }
    return cost;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int *arr = new int(n);
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Min Cost of Ropes = " << minCost(arr, n) << endl;
    return 0;
}