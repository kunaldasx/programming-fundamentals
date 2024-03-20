// Calculate the minimum cost to make a string valid
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int findMinCost(string str)
{
    // Odd condition
    if (str.length() % 2 != 0)
    {
        return -1;
    }

    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            s.push(ch);
        }
        else
        {
            // ch is closed brace
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                // Corresponding opening brace is not found
                s.push(ch);
            }
        }
    }

    // Stack contains invalid expression
    int openCount = 0, closeCount = 0;
    while (!s.empty())
    {
        if (s.top() == '{')
        {
            openCount++;
        }
        else
        {
            closeCount++;
        }
        s.pop();
    }

    int ans = (openCount + 1) / 2 + (closeCount + 1) / 2;
    return ans;
}

int main()
{
    string str = "{{{}}}";
    // string str = "{}}}";

    cout << findMinCost(str) << endl;
    return 0;
}