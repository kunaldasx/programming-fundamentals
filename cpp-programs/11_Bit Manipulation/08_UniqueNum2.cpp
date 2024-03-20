// Find two unique numbers in an array conatining pairs of each number except two
#include <iostream>
using namespace std;

int getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

void unique(int arr[], int n)
{
    int xorSum = 0;
    for (int i = 0; i < n; i++)
    {
        xorSum = xorSum ^ arr[i];
    }

    int tempXor = xorSum;
    int setBit = 0;
    int pos = 0;
    while (setBit != 1)
    {
        setBit = xorSum & 1;
        pos++;
        xorSum = xorSum >> 1;
    }

    int newXor = 0;
    for (int i = 0; i < n; i++)
    {
        if (getBit(arr[i], pos - 1))
        {
            newXor = newXor ^ arr[i];
        }
    }
    cout << newXor << " ";
    cout << (tempXor ^ newXor) << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 7, 1, 5, 2, 3};

    unique(arr, 8);
    return 0;
}
