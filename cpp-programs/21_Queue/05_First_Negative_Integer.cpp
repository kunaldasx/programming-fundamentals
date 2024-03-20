// First Negative Integer in every window of size k
#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeInteger(int A[], int n, int k)
{
    deque<int> dq;
    vector<int> ans;

    // Process First window of k size
    for (int i = 0; i < k; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // Store ans of first k sized window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // Process for remaining windows
    for (int i = k; i < n; i++)
    {
        // Removal
        if (!dq.empty() && i - dq.front() >= k)
        {
            dq.pop_front();
        }

        // Addition
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        // Store Ans
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    int arr[] = {-8, 2, 3, -6, 5};

    vector<int> ans = firstNegativeInteger(arr, 5, 2);
    for (auto element : ans)
    {
        cout << element << " ";
    }
    return 0;
}