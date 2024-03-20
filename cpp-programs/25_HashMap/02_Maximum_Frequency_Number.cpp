// Find the Number with the maximum frequency.
// If two numbers contend for the maximum frequency then return the element which occurs in the array first
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

int maximumFrequency(vector<int> arr)
{
    unordered_map<int, int> count;

    int maxFreq = INT_MIN;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    // This makes sure that if there are more than one numbers with the maxFreq,
    // then it stores the one having the least index as ans
    for (int i = 0; i < arr.size(); i++)
    {
        if (maxFreq == count[arr[i]])
        {
            ans = arr[i];
            break;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr;
    int data;
    cout << "Enter the elements:" << endl;
    cin >> data;
    while (data != -1)
    {
        arr.push_back(data);
        cin >> data;
    }

    cout << "The number with maximum frequency: " << maximumFrequency(arr) << endl;
    return 0;
}