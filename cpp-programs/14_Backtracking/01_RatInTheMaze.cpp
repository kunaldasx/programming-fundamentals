// Rat in the Maze
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1
#include <iostream>
using namespace std;

bool isSafe(int **maze, int x, int y, int n)
{
    if (x < n && y < n && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratinMaze(int **maze, int x, int y, int n, int **solArr)
{

    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, n))
    {
        solArr[x][y] = 1;

        // for downward direction
        if (ratinMaze(maze, x + 1, y, n, solArr))
        {
            return true;
        }

        // for right direction
        if (ratinMaze(maze, x, y + 1, n, solArr))
        {
            return true;
        }
        // Backtrack
        solArr[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    int **maze = new int *[n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] == 0;
        }
    }
    cout << endl;

    if (ratinMaze(maze, 0, 0, n, solArr))
    {
        cout << "*********" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
        cout << "*********" << endl;
    }
    return 0;
}