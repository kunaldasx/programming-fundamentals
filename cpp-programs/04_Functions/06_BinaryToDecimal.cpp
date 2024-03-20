// Binary to decimal
#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int ans = 0;
    int x = 1;

    while (num)
    {
        int y = num % 10;
        ans += x * y;
        num /= 10;
        x *= 2;
    }
    cout << ans << endl;
    return 0;
}