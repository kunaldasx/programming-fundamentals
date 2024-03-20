// Some Important Concepts
#include <iostream>
using namespace std;
#define SIZE 100
#define Area(a, b) (a * b) // Macros

// Inline Functions
inline int sum(int x, int y = 0)
{ // Default Arguments
    return (x + y);
}

int main()
{
    int i = 5;
    int &j = i; // Reference Variable

    cout << j << endl;

    cout << SIZE << endl;

    cout << "Area = " << Area(2, 5) << endl;

    cout << "Sum = " << sum(5, 7) << endl;
    cout << "Sum = " << sum(5) << endl;

    const int a = 5; // Constant variable
    cout << a << endl;
    // a++;  Not possible
    return 0;
}