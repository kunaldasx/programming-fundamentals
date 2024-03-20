// Sudoku Solver
// 0 2 0 0 0 0 0 0 0
// 0 0 0 6 0 0 0 0 3
// 0 7 4 0 8 0 0 0 0
// 0 0 0 0 0 3 0 0 2
// 0 8 0 0 4 0 0 1 0
// 6 0 0 5 0 0 0 0 0
// 0 0 0 0 1 0 7 8 0
// 5 0 0 0 0 9 0 0 0
// 0 0 0 0 0 0 0 4 0
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    for (int i = 0; i < board.size(); i++)
    {
        // row check
        if (board[row][i] == val)
        {
            return false;
        }

        // column check
        if (board[i][col] == val)
        {
            return false;
        }

        // 3x3 matrix check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<int>> &board)
{
    int n = board[0].size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val;

                        // Recursive Call
                        bool restMatrix = sudokuSolver(board); // Check for the rest of the matrix
                        if (restMatrix)
                        {
                            return true;
                        }
                        else
                        {
                            // Backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> board;
    cout << "Enter the elements:" << endl;
    for (int row = 0; row < 9; row++)
    {
        int data;
        vector<int> temp;
        for (int col = 0; col < 9; col++)
        {
            cin >> data;
            temp.push_back(data);
        }
        board.push_back(temp);
    }

    bool ans = sudokuSolver(board);

    cout << "\n**********SOLUTION***********" << endl;
    for (auto u : board)
    {
        for (auto v : u)
        {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}