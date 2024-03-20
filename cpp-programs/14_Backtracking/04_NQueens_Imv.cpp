// N Queeens
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
        ans.push_back(temp);
        temp.clear();
    }
}

// bool isSafe(int row, int col, vector<vector<int>> &board, int n)
// {
//     int x = row;
//     int y = col;

//     // Check row
//     while (y >= 0)
//     {
//         if (board[x][y--] == 1)
//         {
//             return false;
//         }
//     }

//     // Check top left diagonal
//     x = row;
//     y = col;
//     while (x >= 0 && y >= 0)
//     {
//         if (board[x--][y--] == 1)
//         {
//             return false;
//         }
//     }

//     // Check bottom left diagonal
//     x = row;
//     y = col;
//     while (x < n && y >= 0)
//     {
//         if (board[x++][y--] == 1)
//         {
//             return false;
//         }
//     }

//     return true;
// }

// Optimized version for isSafe
bool isSafe(int row, int col, int n, vector<bool> &roww, vector<bool> &upper_left, vector<bool> &bottom_left)
{
    // Check row,, bottom left diagonal, upper left diagonal
    if (roww[row] == true || bottom_left[row + col] == true || upper_left[(n - 1) + (row - col)] == true)
    {
        return false;
    }
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n, vector<bool> &roww, vector<bool> &upper_left, vector<bool> &bottom_left)
{
    // Base Condition
    if (col == n)
    {
        // Store all the data of board into ans
        addSolution(board, ans, n);
        return;
    }

    // Solving for the first column
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, n, roww, upper_left, bottom_left))
        {
            // If placing queen here is safe
            board[row][col] = 1;

            // Update in map
            // For row
            roww[row] = true;
            // For lower left diagonal
            bottom_left[row + col] = true;
            // For upper left diagonal
            upper_left[(n - 1) + (row - col)] = true;

            // Recursive call
            solve(col + 1, ans, board, n, roww, upper_left, bottom_left);
            // Backtrack
            board[row][col] = 0;

            // Undo the changes
            // For row
            roww[row] = false;
            // For lower left diagonal
            bottom_left[row + col] = false;
            // For upper left diagonal
            upper_left[(n - 1) + (row - col)] = false;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    vector<bool> roww(n, false);
    vector<bool> upper_left(2 * n - 2, false);
    vector<bool> bottom_left(2 * n - 2, false);

    solve(0, ans, board, n, roww, upper_left, bottom_left);

    return ans;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> ans = nQueens(n);
    int count = 0;
    for (auto u : ans)
    {
        count++;
        for (auto v : u)
        {
            cout << v << " ";
        }
        cout << endl;
        if (count == n)
        {
            // Inorder to seperate the different solutions
            cout << endl;
            count = 0;
        }
    }
    return 0;
}