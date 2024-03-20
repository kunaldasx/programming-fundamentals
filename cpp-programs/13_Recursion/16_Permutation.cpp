// Print all permutations of a string
#include <iostream>
using namespace std;

void subSeq(string s, string ans)
{

    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);

        subSeq(ros, ans + ch);
    }
}

int main()
{
    string s;
    cin >> s;

    subSeq(s, "");
    return 0;
}