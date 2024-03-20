// Print all subsequences of a string
#include <iostream>
using namespace std;

void subSeq(string s, string ans)
{

    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];

    subSeq(s.substr(1), ans);
    subSeq(s.substr(1), ans + ch);
}

int main()
{
    string s;
    cin >> s;

    subSeq(s, "");
    return 0;
}