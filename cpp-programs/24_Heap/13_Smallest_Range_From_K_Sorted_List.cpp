// Smallest range from k sorted list
#include <iostream>
#include <climits>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

int smallestRange(vector<vector<int>> &kLists, int k, int n)
{
    int mini = INT_MAX, maxi = INT_MIN;
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // Step 1: Insert the starting elements of each list in the heap
    for (int i = 0; i < k; i++)
    {
        int element = kLists[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }

    int start = mini, end = maxi;

    // Precess Ranges
    while (!minHeap.empty())
    {
        // Fetch mini
        Node *temp = minHeap.top();
        minHeap.pop();

        // Update mini
        mini = temp->data;

        // Update range
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // Check if the next element exists
        if (temp->col + 1 < n)
        {
            maxi = max(maxi, kLists[temp->row][temp->col + 1]);
            minHeap.push(new Node(kLists[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else
        {
            // Next element doesn't exists
            break;
        }
    }
    // Returning the difference of range values
    return (end - start + 1);
}

int main()
{
    vector<vector<int>> kLists;

    int k, n;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Enter the value of n: ";
    cin >> n;

    int val;
    for (int i = 0; i < k; i++)
    {
        vector<int> v;
        cout << "Enter the elements for array: " << i + 1 << " " << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> val;
            v.push_back(val);
        }
        kLists.push_back(v);
    }

    cout << "Smallest Range = " << smallestRange(kLists, k, n) << endl;
    return 0;
}