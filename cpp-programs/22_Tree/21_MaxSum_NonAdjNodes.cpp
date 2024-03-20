// Maximum sum of non adjacent nodes
// Kth Ancestor in a tree
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

pair<int, int> solve(node *root)
{
    // Base Condition
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> leftAns = solve(root->left);
    pair<int, int> rightAns = solve(root->right);

    pair<int, int> ans;

    ans.first = root->data + leftAns.second + rightAns.second;

    ans.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return ans;
}

int getMaxSum(node *root)
{
    pair<int, int> ans = solve(root);

    // first --- maximum sum including nodes at current level
    // second --- maximum sum excluding nodes at current level
    return max(ans.first, ans.second);
}

int main()
{
    node *root = NULL;
    buildTreeLOT(root);

    int ans = getMaxSum(root);
    cout << ans << endl;
    return 0;
}