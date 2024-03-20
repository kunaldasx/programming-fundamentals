// Celebrity Problem
#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> M, int a, int b)
{
    if (M[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int detectCelebrity(vector<vector<int>> M, int n)
{
    stack<int> s;
    // Step 1: Push all elements in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // Step 2: Get 2 elements and compare them
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M, a, b))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans = s.top();

    // Step 3: Single element in stack is potential celebrity
    // So verify it

    // Row check
    int zeroCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 0)
        {
            zeroCount++;
        }
    }
    // All zeroes
    if (zeroCount != n)
    {
        return -1;
    }

    // Column check
    int oneCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 1)
        {
            oneCount++;
        }
    }
    if (oneCount != n - 1)
    {
        return -1;
    }

    return ans;
}

int main()
{
    vector<vector<int>> v = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    // vector<vector<int>> v = {{0, 1}, {1, 0}};

    cout << detectCelebrity(v, 3) << " is a Celebrity" << endl;
    return 0;
}