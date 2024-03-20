// Hexadecimal to Decimal
#include <iostream>
using namespace std;

int main()
{
    string num;
    cin >> num;
    int ans = 0;
    int x = 1;

    for (int i = num.size() - 1; i >= 0; i--)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            ans += x * (num[i] - '0');
        }

        else if (num[i] >= 'A' && num[i] <= 'F')
        {
            ans += x * (num[i] - 'A' + 10);
        }
        x *= 16;
    }
    cout << ans << endl;
    return 0;
}