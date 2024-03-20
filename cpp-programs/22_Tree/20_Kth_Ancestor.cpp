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

node *solve(node *root, int &k, int val)
{
    // Base Condition
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == val)
    {
        return root;
    }

    node *leftAns = solve(root->left, k, val);
    node *rightAns = solve(root->right, k, val);

    // Return
    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            // Lock Answer
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            // Lock Answer
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}
int kthAncestor(node *root, int k, int val)
{
    node *ans = solve(root, k, val);
    if (ans == NULL || ans->data == val) // k >= 1
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}

int main()
{
    node *root = NULL;
    buildTreeLOT(root);

    int k, val;
    cin >> k >> val;

    int ans = kthAncestor(root, k, val);
    cout << ans << endl;
    return 0;
}