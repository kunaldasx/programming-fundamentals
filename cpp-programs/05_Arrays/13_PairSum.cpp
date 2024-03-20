// Check if there exists two elements in an array such that their sum is equal to given k
// (It works in a sorted array)
#include <iostream>
#include <climits>
using namespace std;

bool pairSum(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == k)
        {
            cout << low << " " << high << endl;
            return true;
        }
        else if (arr[low] + arr[high] > k)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return false;
}
int main()
{
    // int n, k;
    // cin >> n>>k;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    int arr[] = {2, 4, 7, 11, 14, 16, 20, 21};
    int k = 31;

    cout << pairSum(arr, 8, k) << endl;
    return 0;
}
