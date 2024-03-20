// Rotate Arrays
#include <iostream>
#include <vector>
using namespace std;

void roatateArray(vector<int> &v, int k)
{
    vector<int> temp(v.size());

    for (int i = 0; i < v.size(); i++)
    {
        temp[(i + k) % v.size()] = v[i];
    }

    v = temp;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(10);
    v.push_back(15);
    v.push_back(35);

    roatateArray(v, 2);

    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}