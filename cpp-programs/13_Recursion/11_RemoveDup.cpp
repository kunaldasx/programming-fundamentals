// Remove all duplicates from a string
#include <iostream>
using namespace std;

string removeDup(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    string ans = removeDup(s.substr(1));

    if (ch == ans[0])
    {
        return ans;
    }
    return (ch + ans);
}

int main()
{
    string s;
    cin >> s;

    cout << removeDup(s) << endl;
    return 0;
}