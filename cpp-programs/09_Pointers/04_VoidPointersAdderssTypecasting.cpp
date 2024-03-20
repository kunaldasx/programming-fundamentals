// Note that the program compiles in C, but doesn’t compile in C++. In C++, we must explicitly typecast
// return value of malloc to (int *). 2) void pointers in C are used to implement generic functions in C. For
// example compare function which is used in qsort(). Some Interesting Facts: 1) void pointers cannot be
// dereferenced. For example the following program doesn’t compile.

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    void *ptr = &a; // Void pointer

    // cout << *ptr << endl;   // This doesn't execute
    cout << *(int *)ptr << endl;

    int I = 65;
    char *p = (char *)&I; // Pointer address typecasting

    cout << *p << endl;

    return 0;
}