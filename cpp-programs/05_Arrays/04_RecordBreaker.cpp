// Record Breaker
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    arr[n] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max && arr[i] > arr[i + 1])
        {
            cout << i << " ";
            max = arr[i];
        }
    }
    cout << endl;
    return 0;
}
