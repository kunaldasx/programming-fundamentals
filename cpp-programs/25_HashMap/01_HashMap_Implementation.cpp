// HashMap Implementation
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    // Creation
    // unordered_map<string, int> m;  // Insertion Complesity --- O(1)
    map<string, int> m; // Insertion Complesity --- O(logN)

    // Insertion

    // 1
    pair<string, int> p = make_pair("Ajay", 3);
    m.insert(p);

    // 2
    pair<string, int> pair2("Shradha", 2);
    m.insert(pair2);

    // 3
    m["Ananya"] = 1;

    // Search
    cout << m["Shradha"] << endl;
    cout << m.at("Ananya") << endl;

    // cout << m.at("Unknown") << endl;   ---- This will give an error because the key doesn't exist
    cout << m["Unknown"] << endl;    // This will print 0 --- since it creates a new entry 'Unknown' corresponding to 0
    cout << m.at("Unknown") << endl; // Now this will also print 0

    // Size
    cout << m.size() << endl;

    // Check presence
    cout << m.count("Ajay") << endl; // Gives 0 if not present and 1 if present
    cout << m.count("Bro") << endl;

    // Erase
    m.erase("Ananya");
    cout << m.size() << endl;

    // Traverse
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    // Iterator
    // unordered_map<string, int>::iterator it = m.begin();
    map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}