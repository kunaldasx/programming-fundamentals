// Circular Tour
#include <bits/stdc++.h>
using namespace std;

class PetrolPump
{
public:
    int petrol;
    int distance;
};

int main()
{
    PetrolPump p[6] = {{6, 5}, {7, 6}, {4, 7}, {10, 8}, {6, 6}, {5, 4}};

    int n = 6;
    int start = 0;
    int balance = 0;
    int deficit = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0)
    {
        cout << start << endl;
    }
    else
    {
        cout << "-1" << endl;
    }

    return 0;
}