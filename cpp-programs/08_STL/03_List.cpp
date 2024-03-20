// List
#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;

    l.push_back(1);
    l.push_front(2); // 2 1

    for (auto element : l)
    {
        cout << element << " ";
    }
    cout << endl;

    l.erase(l.begin()); // 1

    l.push_back(2);
    l.push_back(3); // 1 2 3

    cout << l.size() << endl; // 3

    l.pop_back();  // 1 2
    l.pop_front(); // 2

    for (auto element : l)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}