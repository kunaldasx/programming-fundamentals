// Check if a given character is a vowel or a consonant
#include <iostream>
using namespace std;

int main()
{
    char ch;
    cin >> ch;

    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        cout << "Vowel" << endl;
    }
    else
    {
        cout << "Consonant" << endl;
    }
    return 0;
}