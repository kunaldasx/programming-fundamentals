// Max circular subarray sum
#include <iostream>
#include <climits>
using namespace std;

int kadane(int arr[], int n)
{
    int sum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
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

    int wrapSum;
    int nonWrapSum;
    int totalSum = 0;

    nonWrapSum = kadane(arr, n);

    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
        arr[i] = -arr[i];
    }

    wrapSum = totalSum + kadane(arr, n); // total - (-non Contributing element)

    // cout << totalSum << " " << kadane(arr, n) << endl;
    // cout << wrapSum << " " << nonWrapSum << endl;
    cout << max(wrapSum, nonWrapSum) << endl;

    return 0;
}
