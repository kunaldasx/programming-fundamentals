// Check if a word is palindrome
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char ch[n + 1];
    cin >> ch;

    int i = 0;
    while (ch[i] != '\0')
    {
        if (ch[i] != ch[n - 1 - i])
        {
            cout << "Not Palindrome" << endl;
            return 0;
        }
        i++;
    }
    cout << "Palindrome" << endl;
    return 0;
}