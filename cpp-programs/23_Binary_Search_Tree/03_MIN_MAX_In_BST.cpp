// MIN and MAX value in BST
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

// Find Min value
int minValue(Node *root)
{
    Node *curr = root;

    while (curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr->data;
}

// Find Max value
int maxValue(Node *root)
{
    Node *curr = root;

    while (curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr->data;
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    buildTree(root);

    cout << "Min value: " << minValue(root) << endl;
    cout << "Max value: " << maxValue(root) << endl;
    return 0;
}