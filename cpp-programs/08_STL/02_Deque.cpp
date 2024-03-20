// Deque
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);

    cout << d.at(0) << endl;
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;

    // d.push_front(7);
    // cout << d.at(0) << endl;
    // for (int i : d)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // d.pop_back();
    // for (int i : d)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // d.pop_front();
    // for (int i : d)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    cout << d.front() << endl;
    cout << d.back() << endl;

    cout << d.empty() << endl;

    cout << d.size() << endl;
    d.erase(d.begin(), d.begin() + 1);

    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}