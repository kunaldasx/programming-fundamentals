// Map
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> m;

    m[1] = "Ram";
    m[2] = "Ravi";
    m[13] = "Shradha";

    m.insert({5, "Ajay"});

    for (auto i : m)
    {
        cout << i.first << "->";
        cout << i.second << endl;
    }
    cout << endl;

    cout << "Find 13: " << m.count(13) << endl;
    cout << "Find -13: " << m.count(-13) << endl;

    m.erase(13);
    for (auto i : m)
    {
        cout << i.first << "->";
        cout << i.second << endl;
    }

    auto it = m.find(2);
    for (auto i = it; i != m.end(); i++)
    {
        // cout << (*i).first << " ";
        cout << i->first << " ";
    }
    cout << endl;
    return 0;
}