// Convert whole string to upper case
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;

    // transform(str.begin(), str.end(), str.begin(), ::toupper);
    // transform(str.begin(), str.end(), str.begin(), ::tolower);
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    cout << str << endl;
    return 0;
}