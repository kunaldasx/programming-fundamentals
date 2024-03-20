// Merge K sorted Arrays
#include <iostream>
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

vector<int> mergeKSortedArrays(vector<vector<int>> kArrays, int k)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    // Step 1: Insert the first elements from all the arrays
    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // Step 2:
    while (minHeap.size() > 0)
    {
        Node *temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int row = temp->row;
        int col = temp->col;

        if (col + 1 < kArrays[row].size())
        {
            Node *next = new Node(kArrays[row][col + 1], row, col + 1);
            minHeap.push(next);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> kArrays;

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    int n, val;
    for (int i = 0; i < k; i++)
    {
        vector<int> v;
        cout << "Enter size of array: " << i + 1 << ": ";
        cin >> n;
        cout << "Enter the elements for array: " << i + 1 << " " << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> val;
            v.push_back(val);
        }
        kArrays.push_back(v);
    }

    vector<int> ans = mergeKSortedArrays(kArrays, k);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}