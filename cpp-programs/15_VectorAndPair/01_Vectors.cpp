// Vectors
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.size(); i++)
    {
        // cout << v[i] << " ";
        cout << v.at(i) << " ";
    } // 1 2 3
    cout << endl;

    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl; // 1 2 3

    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl; // 1 2 3

    v.pop_back();

    vector<int> v2(3, 50);

    v.swap(v2); // swap(v, v2)

    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;

    for (auto element : v2)
    {
        cout << element << " ";
    }
    cout << endl;

    vector<int> a1 = {1, 2};
    vector<int> a(a1);
    cout << "Capacity: " << a.capacity() << endl;
    cout << "Size: " << a.size() << endl;
    a.push_back(3);
    cout << "Capacity: " << a.capacity() << endl;

    cout << "Start Index: " << a.front() << endl;
    cout << "End Index: " << a.back() << endl;
    return 0;
}