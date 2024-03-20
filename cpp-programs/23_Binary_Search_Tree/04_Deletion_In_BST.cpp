// Delete a node from a BST
#include <iostream>
#include <queue>
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

// In-order Traversal
void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // LNR (Left Node Right)
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

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

Node *deleteFromBST(Node *root, int val)
{
    // Base Condition
    if (root == NULL)
    {
        return root;
    }

    // Found the node
    if (root->data == val)
    {
        // 0 Child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 Child

        // Left Child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Right Child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 Child
        if (root->left != NULL && root->right != NULL)
        {
            // Find the min node from right subtree
            int mini = minValue(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    // Visit Left subtree
    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }

    // Visit Right subtree
    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    buildTree(root);

    int val;
    cin >> val;

    root = deleteFromBST(root, val);

    inOrderTraversal(root);

    return 0;
}