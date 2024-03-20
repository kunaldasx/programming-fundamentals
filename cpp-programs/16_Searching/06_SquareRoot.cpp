// Square root of a number using binary search
#include <iostream>
using namespace std;

long long int squareRoot(int n)
{
    int si = 0;
    int ei = n;
    long long int ans = -1;

    while (si <= ei)
    {
        int mid = si + (ei - si) / 2;
        long long int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        else if (square < n)
        {
            ans = mid;
            si = mid + 1;
        }
        else
        {
            ei = mid - 1;
        }
    }
    return ans;
}

double morePrecision(int n, int precision)
{
    int tempSol = squareRoot(n);
    double ans = tempSol;
    double factor = 1;

    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double i = ans; i * i < n; i += factor)
        {
            ans = i;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << morePrecision(n, 3) << endl;
    return 0;
}