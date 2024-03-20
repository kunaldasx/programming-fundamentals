// Find the maximum area of a rectangle formed only of 1s in the given matrix
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(int arr[], int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(int arr[], int n)
{
    stack<int> s;
    s.push(-1);

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangularArea(int arr[], int n)
{
    vector<int> next;
    next = nextSmallerElement(arr, n);

    vector<int> prev;
    prev = prevSmallerElement(arr, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = arr[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int maxArea(int M[][4], int row, int col)
{
    // Compute area for 1st row
    int area = largestRectangularArea(M[0], col);

    // For remaining rows
    for (int i = 1; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // Update row by adding previous row's value
            if (M[i][j] != 0)
            {
                M[i][j] += M[i - 1][j];
            }
        }

        // Now the entire row is updated
        area = max(area, largestRectangularArea(M[i], col));
    }
    return area;
}

int main()
{
    int arr[][4] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

    cout << "Largest Rectangular Area = " << maxArea(arr, 4, 4) << endl;

    return 0;
}