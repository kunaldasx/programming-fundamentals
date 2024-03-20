// Decimal to Binary
// #include <iostream>
// using namespace std;

// int main()
// {
//     int num;
//     cin >> num;

//     int binaryNum[10], i = 0;
//     while (num)
//     {
//         binaryNum[i++] = num % 2;
//         num /= 2;
//     }
//     for (int j = i - 1; j >= 0; j--)
//     {
//         cout << binaryNum[j];
//     }
//     cout << endl;
//     return 0;
// }

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 0, i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i++)) + ans;
        n = n >> 1;
    }
    cout << ans << endl;
    return 0;
}