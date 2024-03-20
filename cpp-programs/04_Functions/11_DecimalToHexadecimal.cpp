// Decimal to Hexadecimal
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;

    char hexNum[10], i = 0;
    while (num)
    {
        int temp = num % 16;
        if (temp < 10)
        {
            hexNum[i++] = temp + '0';
        }
        else
        {
            hexNum[i++] = temp + 'A' - 10;
        }
        num /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        cout << hexNum[j];
    }
    cout << endl;
    return 10;
}