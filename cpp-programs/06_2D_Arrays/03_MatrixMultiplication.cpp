// Matrix Multiplication
#include <iostream>
using namespace std;

int main()
{
    int r1, c1;
    cin >> r1 >> c1;
    int F[r1][c1];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cin >> F[i][j];
        }
    }

    int r2, c2;
    cin >> r2 >> c2;
    if (c1 != r2)
    {
        cout << "Invalid order of matrix" << endl;
        return 0;
    }

    int S[r2][c2];
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> S[i][j];
        }
    }

    int ans[r1][c2];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            ans[i][j] = 0;
            for (int k = 0; k < r2; k++) // r2 = c1
            {
                ans[i][j] += F[i][k] * S[k][j];
            }
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}