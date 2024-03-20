// Array STL
#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 5> a = {1, 2, 3, 4, 5};

    int size = a.size();
    cout << "Size = " << size << endl;

    for (int i = 0; i < size; i++)
    {
        // cout<<a[i]<<" ";
        cout << a.at(i) << " ";
    }
    cout << endl;

    cout << "Empty or Not: " << a.empty() << endl;

    cout << "Start Index: " << a.front() << endl;
    cout << "End Index: " << a.back() << endl;
    return 0;
}