// Place k cows in the stalls such that the minimum distance between them is maximum
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int stalls[], int n, int k, int mid)
{
    int cowCount = 1;
    int lastpos = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastpos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastpos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(int stalls[], int n, int k)
{
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, stalls[i]);
    }

    int si = 0;
    int ei = maxi;
    int ans = -1;

    while (si <= ei)
    {
        int mid = si + (ei - si) / 2;
        if (isPossible(stalls, n, k, mid))
        {
            ans = mid;
            si = mid + 1;
        }
        else
        {
            ei = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int stalls[] = {1, 2, 3, 4, 6};
    cout << aggressiveCows(stalls, 5, 2) << endl;
    return 0;
}