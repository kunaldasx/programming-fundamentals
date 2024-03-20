// Reverse a string using Stack
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str;
    cin >> str;

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    string ans = "";

    while (!s.empty())
    {
        char ch = s.top();
        s.pop();
        ans.push_back(ch);
    }
    cout << "Answer is: " << ans << endl;
    return 0;
}
