// Find the size of the largest subtree of a binary tree
#include <iostream>
#include <queue>
#include <climits>
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

// Build Tree from level order traversal (Binary Tree)
void buildTreeLOT(Node *&root)
{
    queue<Node *> q;
    cout << "Enter data for root: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter data for left Node of " << temp->data << ": ";
        int leftNode;
        cin >> leftNode;

        if (leftNode != -1)
        {
            temp->left = new Node(leftNode);
            q.push(temp->left);
        }

        cout << "Enter data for right Node of " << temp->data << ": ";
        int rightNode;
        cin >> rightNode;

        if (rightNode != -1)
        {
            temp->right = new Node(rightNode);
            q.push(temp->right);
        }
    }
}

class Info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

// Support function
Info solve(Node *root, int &maxSize)
{
    // Base Condition
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0}; // Refer 85 and 86
    }

    // Process for left and right subtree
    Info left = solve(root->left, maxSize);
    Info right = solve(root->right, maxSize);

    // Process current Node
    Info curr;
    curr.size = left.size + right.size + 1;
    curr.maxi = max(root->data, right.maxi);
    curr.mini = min(root->data, left.mini);

    // Check BST
    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        curr.isBST = true;

        // Update maxSize
        maxSize = max(maxSize, curr.size);
    }
    else
    {
        curr.isBST = false;
    }

    return curr;
}

// Main
int largestBST(Node *root)
{
    int maxSize = 0;
    Info temp = solve(root, maxSize);
    return maxSize;
}

int main()
{
    Node *root = NULL;
    buildTreeLOT(root);

    cout << "Largest BST: " << largestBST(root) << endl;
    return 0;
}