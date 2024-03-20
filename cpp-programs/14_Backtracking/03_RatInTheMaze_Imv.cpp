// Rat int the maze Improved
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &arr, vector<vector<bool>> visited, int n)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && arr[x][y] == 1 && visited[x][y] != 1)
    {
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
{
    // Base Case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // Movement ---- D L R U

    visited[x][y] = 1;

    // Down
    if (isSafe(x + 1, y, arr, visited, n))
    {
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
    }

    // Right
    if (isSafe(x, y + 1, arr, visited, n))
    {
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
    }

    // Left
    if (isSafe(x, y - 1, arr, visited, n))
    {
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
    }

    // Up
    if (isSafe(x - 1, y, arr, visited, n))
    {
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
    }
    visited[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";

    if (arr[0][0] == 0)
    {
        return ans;
    }

    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}

int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<string> ans = searchMaze(arr, n);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}