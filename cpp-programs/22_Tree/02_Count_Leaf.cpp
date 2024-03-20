// Count all the leaf nodes of a binary tree
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

node *buildTree(node *root)
{
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for the left node of " << data << ": ";
    root->left = buildTree(root->left);

    cout << "Enter data for the right node of " << data << ": ";
    root->right = buildTree(root->right);

    return root;
}

// Count leaf nodes
void countLeaf(node *root, int &count)
{
    // Using Inorder

    // Base Condition
    if (root == NULL)
    {
        return;
    }

    countLeaf(root->left, count);

    // Leaf node
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }

    countLeaf(root->right, count);
}

int main()
{
    node *root = NULL;
    root = buildTree(root);

    int count = 0;
    countLeaf(root, count);

    cout << "Total Leaf nodes = " << count << endl;
    return 0;
}