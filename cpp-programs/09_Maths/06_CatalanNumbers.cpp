// Catalan Numbers
#include <iostream>
#include <vector>
using namespace std;

vector<int> catalanNum(int n)
{
    vector<int> cat(n);
    cat[0] = 1;
    cat[1] = 1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cat[i] += cat[j] * cat[i - j - 1];
        }
    }
    return cat;
}

int main()
{
    int n;
    cin >> n;
    vector<int> cat = catalanNum(n);
    for (auto element : cat)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}