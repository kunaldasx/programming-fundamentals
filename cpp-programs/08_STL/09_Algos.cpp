// Some Important Algos
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7); // 1 3 6 7

    cout << "Find 6: " << binary_search(v.begin(), v.end(), 6) << endl;
    cout << "Find 10: " << binary_search(v.begin(), v.end(), 10) << endl;

    cout << "Lower Bound: " << lower_bound(v.begin(), v.end(), 6) - v.begin() << endl;
    cout << "Upper Bound: " << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl;

    rotate(v.begin(), v.begin() + 1, v.end()); // 3 6 7 1

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    int a = 3;
    int b = 5;

    cout << "Max = " << max(a, b) << endl;
    cout << "Min = " << min(a, b) << endl;

    swap(a, b);
    cout << "a->" << a << endl;

    string s = "abcd";
    reverse(s.begin(), s.end());
    cout << "String: " << s << endl;
    return 0;
}