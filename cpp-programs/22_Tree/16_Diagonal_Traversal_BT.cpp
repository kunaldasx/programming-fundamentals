// Diagonal traversal in a binary tree
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

vector<int> diagonalTraversal(node *root)
{
    queue<node *> q;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    q.push(root);

    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();

        while (curr)
        {
            if (curr->left)
            {
                q.push(curr->left);
            }
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
    return ans;
}

int main()
{
    node *root = NULL;
    buildTreeLOT(root);

    vector<int> ans = diagonalTraversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}