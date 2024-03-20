#include <iostream>
using namespace std;

int main()
{
    int num1, num2, max;
    cin >> num1 >> num2;

    max = (num1 > num2) ? num1 : num2;
    int pro = max;
    while (1)
    {
        if (pro % num1 == 0 && pro % num2 == 0)
        {
            cout << "LCM: " << pro;
            break;
        }
        pro += max;
    }
    return 0;
}