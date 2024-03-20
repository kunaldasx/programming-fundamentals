// Add Two Arrays
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> reverse(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;

    while (s <= e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}

vector<int> sum(vector<int> v1, vector<int> v2)
{
    int i = v1.size() - 1;
    int j = v2.size() - 1;
    int carry = 0;

    vector<int> ans;

    while (i >= 0 && j >= 0)
    {
        int sum = v1[i] + v2[j] + carry;

        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while (i >= 0)
    {
        int sum = v1[i] + carry;

        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    while (j >= 0)
    {
        int sum = v2[j] + carry;

        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    return reverse(ans);
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    vector<int> v2;
    v2.push_back(7);
    v2.push_back(9);

    vector<int> ans = sum(v1, v2);

    for (auto element : ans)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}