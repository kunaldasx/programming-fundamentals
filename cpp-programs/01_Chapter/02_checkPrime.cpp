// Cpp progarm to check if a number is prime or not

#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int prime = 1;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            prime = 0;
            break;
        }
    }

    if (num == 1)
    {
        cout << "It is neither prime nor composite\n";
    }
    else if (prime)
    {
        cout << "It is prime\n";
    }
    else
    {
        cout << "It is non-prime\n";
    }

    return 0;
}