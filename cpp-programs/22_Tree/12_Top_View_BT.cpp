// Top view of a binary tree
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

vector<int> topView(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    map<int, int> topNode;      // Hd & node->data
    queue<pair<node *, int>> q; // Node & hd
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> curr = q.front();
        q.pop();

        node *frontNode = curr.first;
        int hd = curr.second; // Horizontal Distance

        // If one value is already present in a particular horizontal distance, then don't include the other values in the same hd
        if (topNode.find(hd) == topNode.end())
        {
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    for (auto i : topNode)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    node *root = NULL;
    buildTreeLOT(root);

    vector<int> ans = topView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}