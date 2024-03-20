// Check Rotated Sorted Array
#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> v)
{
    int count = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] > v[i])
        {
            count++;
        }
    }
    if (v[v.size() - 1] > v[0])
    {
        count++;
    }
    return (count <= 1);
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(1);
    v.push_back(9);

    cout << check(v) << endl;
    return 0;
}