// Sum of first n natural numbers
#include <iostream>
using namespace std;

int sum(int n)
{
    return (n * (n + 1)) / 2;
}
int main()
{
    int n;
    cin >> n;

    cout << sum(n) << endl;
    return 0;
}