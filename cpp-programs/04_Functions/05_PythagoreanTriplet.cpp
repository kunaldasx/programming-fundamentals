// Check Pythagorean triplet
#include <iostream>
using namespace std;

bool check(int x, int y, int z)
{
    if ((x * x) == (y * y) + (z * z) || (y * y) == (x * x) + (z * z) || (z * z) == (x * x) + (y * y))
    {
        return true;
    }
    return false;
}
int main()
{
    int x, y, z;
    cin >> x >> y >> z;

    if (check(x, y, z))
    {
        cout << "Pythagorean triplet" << endl;
    }
    else
    {
        cout << "Not Pythagorean triplet" << endl;
    }
    return 0;
}