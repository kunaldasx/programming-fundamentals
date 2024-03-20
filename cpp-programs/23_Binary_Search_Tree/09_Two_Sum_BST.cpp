// Two sum in a BST
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

bool twoSumBST(Node *root, int target)
{
    vector<int> inOrderVal;
    // Store inOrder -> sorted values in vector
    inOrder(root, inOrderVal);

    // Use two pointer approach to check if pair exists
    int i = 0, j = inOrderVal.size() - 1;
    while (i < j)
    {
        int sum = inOrderVal[i] + inOrderVal[j];
        if (sum == target)
        {
            cout << inOrderVal[i] << " & " << inOrderVal[j] << endl;
            return true;
        }

        else if (sum > target)
        {
            j--;
        }

        else
        {
            i++;
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

    cout << twoSumBST(root, target) << endl;
    return 0;
}