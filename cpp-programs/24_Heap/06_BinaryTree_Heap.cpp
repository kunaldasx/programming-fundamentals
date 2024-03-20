// Check whether the given binary tree follows the max heap property or not
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

// Build Tree from level order traversal
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

// Count the total number of nodes in a binary tree
int countNode(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    int ans = 1 + countNode(root->left) + countNode(root->right);
    return ans;
}

// Check if it's a complete binary tree
bool isCBT(Node *root, int index, int count)
{
    if (root == NULL)
    {
        return true;
    }

    if (index >= count)
    {
        return false;
    }

    else
    {
        bool left = isCBT(root->left, 2 * index + 1, count);
        bool right = isCBT(root->right, 2 * index + 2, count);
        return (left && right);
    }
}

// check if the complete binary tree follows the max heap property
bool isMaxOrder(Node *root)
{
    // Leaf Node
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    // Only left Child exists
    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }

    // Both left and right child exists
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}

bool isHeap(Node *root)
{
    int index = 0;
    int totalCount = countNode(root);
    if (isCBT(root, index, totalCount) && isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Node *root = NULL;
    buildTreeLOT(root);

    if (isHeap(root))
        cout << "It's a Heap" << endl;
    else
        cout << "It's not a Heap" << endl;

    return 0;
}