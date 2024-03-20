// Find the longest word in a sentence
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    char ch[n + 1];
    cin.getline(ch, n + 1);

    int i = 0, len = 0, maxLen = 0, si = 0, maxSi = 0;
    while (1)
    {
        if (ch[i] == ' ' || ch[i] == '\0')
        {
            if (len > maxLen)
            {
                maxLen = len;
                maxSi = si;
            }
            len = 0;
            si = i + 1;
        }
        else
        {
            len++;
        }
        if (ch[i] == '\0')
        {
            break;
        }
        i++;
    }

    cout << maxLen << endl;
    for (int i = 0; i < maxLen; i++)
    {
        cout << ch[i + maxSi];
    }
    cout << endl;
    return 0;
}