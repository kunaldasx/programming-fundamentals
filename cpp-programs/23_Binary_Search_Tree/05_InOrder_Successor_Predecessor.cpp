// Find the Inorder successor and predecessor of a node in a BST
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

// Successor and Predecessor
pair<int, int> findSucPre(Node *root, int data)
{
    // First --- successor
    // Second --- predecessor
    pair<int, int> ans = make_pair(-1, -1);

    // Successor
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->data > data)
        {
            ans.first = curr->data;
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    // Predecessor
    curr = root;
    while (curr != NULL)
    {
        if (curr->data < data)
        {
            ans.second = curr->data;
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    return ans;
}

int main()
{
    Node *root = NULL;
    buildTree(root);

    int data;
    cout << "Enter target: ";
    cin >> data;

    pair<int, int> ans = findSucPre(root, data);
    cout << "Successor of " << data << ": " << ans.first << endl;
    cout << "Predecessor of " << data << ": " << ans.second << endl;

    return 0;
}