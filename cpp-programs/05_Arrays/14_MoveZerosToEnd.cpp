// Move all zeros to the end of the array
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &v, int i, int idx)
{
    int temp = v[i];
    v[i] = v[idx];
    v[idx] = temp;
}

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(7);
    v.push_back(5);
    v.push_back(0);
    v.push_back(0);

    int idx = 0;
    int i = 0;
    while (i < v.size())
    {
        if (v[i] == 0)
        {
            i++;
        }
        else
        {
            swap(v, i, idx);
            idx++;
            i++;
        }
    }

    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}