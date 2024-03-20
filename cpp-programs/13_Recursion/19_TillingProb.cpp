// Tilling Problem
#include <iostream>
using namespace std;

int tillingWays(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return tillingWays(n - 1) + tillingWays(n - 2);
}

int main()
{
    int n;
    cin >> n;

    cout << tillingWays(n) << endl;
    return 0;
}