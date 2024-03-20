// Pointer basics
#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    int *ptr = &a;

    cout << *ptr << endl;

    int **pptr = &ptr;
    cout << *pptr << endl;
    cout << **pptr << endl;
    return 0;
}