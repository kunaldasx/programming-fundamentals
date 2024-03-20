// Check if a number is a power of two
#include <iostream>
using namespace std;

int isPowerof2(int n)
{
    return (n && !(n & (n - 1)));
}

int main()
{
    int n;
    cin >> n;

    cout << isPowerof2(n) << endl;
    return 0;
}