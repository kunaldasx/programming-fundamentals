// Lowest Common Ancestor of two nodes in a BST
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *&root, int data)
{
    // Base Condition
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        // Insert in the right subtree
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        // Insert in the left subtree
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

// Creating a BST
void buildTree(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Recursive Appraoch
// Time --- O(n)
// Space --- O(H)
int LCA(Node *root, int n1, int n2)
{
    // Base Condition
    if (root == NULL)
    {
        return -1;
    }

    if (root->data < n1 && root->data < n2)
    {
        return LCA(root->right, n1, n1);
    }

    if (root->data > n1 && root->data > n2)
    {
        return LCA(root->left, n1, n1);
    }

    // If root->data lies in between n1 and n2
    return root->data;
}

// Iterative Appraoch
// Time --- O(n)
// Space --- O(1)
int LCA_Iterative(Node *root, int n1, int n2)
{
    while (root != NULL)
    {
        if (root->data < n1 && root->data < n2)
        {
            root = root->right;
        }

        if (root->data > n1 && root->data > n2)
        {
            root = root->left;
        }
        else
        {
            // If root->data lies in between n1 and n2
            return root->data;
        }
    }
    return -1;
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    buildTree(root);

    int n1, n2;
    cout << "Enter n1 and n2: ";
    cin >> n1 >> n2;

    cout << "Lowest common Ancestor of " << n1 << " and " << n2 << ": " << LCA(root, n1, n2) << endl;
    cout << "Lowest common Ancestor of " << n1 << " and " << n2 << ": " << LCA_Iterative(root, n1, n2) << endl;
    return 0;
}