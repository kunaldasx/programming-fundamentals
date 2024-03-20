// Find the most frequent character in a string
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int freq[26];

    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i] - 'a']++;
    }

    int max = 0;
    char ans;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > max)
        {
            max = freq[i];
            ans = i + 'a';
        }
    }

    cout << max << " " << ans << endl;
    return 0;
}
