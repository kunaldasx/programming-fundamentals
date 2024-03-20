// Flatten BST to a sorted list
#include <iostream>
#include <vector>
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

void inOrder(Node *root, vector<int> &inOrderVal)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left, inOrderVal);
    inOrderVal.push_back(root->data);
    inOrder(root->right, inOrderVal);
}

Node *flattenBST(Node *root)
{
    vector<int> inOrderVal;
    // Store inOrder -> sorted values in vector
    inOrder(root, inOrderVal);

    Node *newRoot = new Node(inOrderVal[0]);

    Node *curr = newRoot;

    // Link all the nodes except the last node
    for (int i = 1; i < inOrderVal.size(); i++)
    {
        Node *temp = new Node(inOrderVal[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // Point the left and right of last node to NULL
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->right;
    }
    cout << "NULL" << endl;
}

int main()
{

    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    buildTree(root);

    root = flattenBST(root);

    print(root);
    return 0;
}