// Checking if a number is Armstrong
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int n2 = n;
    int sum = 0;

    while (n)
    {
        int rem = n % 10;
        sum += pow(rem, 3);
        n /= 10;
    }
    if (sum == n2)
    {
        cout << "Armstrong" << endl;
    }
    else
    {
        cout << "Not Armstrong" << endl;
    }
    return 0;
}
