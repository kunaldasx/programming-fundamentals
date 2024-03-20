// K sum paths
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildTreeLOT(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root: ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter data for left node of " << temp->data << ": ";
        int leftNode;
        cin >> leftNode;

        if (leftNode != -1)
        {
            temp->left = new node(leftNode);
            q.push(temp->left);
        }

        cout << "Enter data for right node of " << temp->data << ": ";
        int rightNode;
        cin >> rightNode;

        if (rightNode != -1)
        {
            temp->right = new node(rightNode);
            q.push(temp->right);
        }
    }
}

void solve(node *root, int k, int &count, vector<int> path)
{
    // Base Condition
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);

    // Left
    solve(root->left, k, count, path);

    // Right
    solve(root->right, k, count, path);

    // Check for k sum
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
        {
            count++;
        }
    }
}

int sumK(node *root, int k)
{
    vector<int> path;
    int count = 0;

    solve(root, k, count, path);
    return count;
}

int main()
{
    node *root = NULL;
    buildTreeLOT(root);

    int k;
    cin >> k;

    int ans = sumK(root, k);
    cout << ans << endl;
    return 0;
}