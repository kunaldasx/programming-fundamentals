// Cpp program to convert temperature from celcius to fahrenheit

#include <iostream>
using namespace std;

int main()
{
    int cel;
    cout << "Enter temperature (in Cecius): ";
    cin >> cel;
    int fah = (9 / 5 * cel) + 32;
    cout << "Temperature in Fahrenheit: " << fah << endl;
    return 0;
}