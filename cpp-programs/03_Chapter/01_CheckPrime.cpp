// Checking if a number is prime
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    cin >> num;
    bool prime = true;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            cout << "Non-Prime" << endl;
            prime = false;
            break;
        }
    }
    if (prime)
    {
        cout << "Prime" << endl;
    }
    return 0;
}