// Matrix Serach (works in a sorted matrix)
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int target;
    cin >> target;

    int r = 0, c = m - 1;
    while (r < n && c >= 0)
    {
        if (arr[r][c] == target)
        {
            cout << "True" << endl;
            return 0;
        }
        arr[r][c] > target ? c-- : r++;
    }

    cout << "False" << endl;
    return 0;
}