// Search an element in a BST
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

// Search in BST Recursion
bool searchInBST(Node *root, int target)
{
    // Base Condition
    if (root == NULL)
    {
        return false;
    }

    if (root->data = target)
    {
        return true;
    }

    if (root->data > target)
    {
        return searchInBST(root->left, target);
    }
    else
    {
        return searchInBST(root->right, target);
    }
}

// Search in BST Iteration
bool searchInBST_Iterative(Node *root, int target)
{
    Node *curr = root;

    while (curr != NULL)
    {
        if (curr->data == target)
        {
            return true;
        }
        if (curr->data > target)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return false;
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    buildTree(root);

    int target;
    cout << "Enter target: ";
    cin >> target;

    cout << searchInBST(root, target) << endl;
    cout << searchInBST_Iterative(root, target) << endl;
    return 0;
}