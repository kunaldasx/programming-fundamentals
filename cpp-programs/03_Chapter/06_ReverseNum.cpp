// Reverse a Number
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int rev = 0;

    while (n)
    {
        int rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }

    cout << rev << endl;
    return 0;
}