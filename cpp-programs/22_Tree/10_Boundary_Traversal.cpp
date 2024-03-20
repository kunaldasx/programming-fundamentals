// Boundary Traversal in Binary Tree
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

// Function to Traverse on the left boundary of a binary tree
void traverseLeft(node *root, vector<int> &ans)
{
    // Base Condition
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->right, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}

// Function to Traverse on the leaf nodes of a binary tree
void traverseLeaf(node *root, vector<int> &ans)
{
    // Base Condition
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

// Function to traverse the right nodes of a binary tree
void traverseRight(node *root, vector<int> &ans)
{
    // Base Condition
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }

    // Store the ans when you return
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(node *root)
{
    vector<int> ans;
    // Base Condition
    if (root == NULL)
    {
        return ans;
    }

    ans.push_back(root->data);

    // Store Left part
    traverseLeft(root->left, ans);

    // Store Leaf nodes

    // Left subtree
    traverseLeaf(root->left, ans);

    // Right subtree
    traverseLeaf(root->right, ans);

    // Store Right part in reverse
    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    node *root = NULL;
    buildTreeLOT(root);

    vector<int> ans = boundaryTraversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}