// Decimal to Octal
#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    int octalNum[10], i = 0;
    while (num)
    {
        octalNum[i++] = num % 8;
        num /= 8;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        cout << octalNum[j];
    }
    cout << endl;
    return 0;
}