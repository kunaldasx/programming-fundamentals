// First non-repeating character in a stream
#include <bits/stdc++.h>
using namespace std;

string firstNonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // Increase count
        count[ch]++;

        // Push in queue
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                // Repeating Character
                q.pop();
            }
            else
            {
                // Non-repeating Character
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string A = "aabc";

    string ans = firstNonRepeating(A);
    cout << ans << endl;
    return 0;
}