// Normal BST to balanced BST
#include <iostream>
#include <vector>
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

// Level order Traversal
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // Current Level is complete
        if (temp == NULL)
        {
            cout << endl;

            // Queue still has some child nodes
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " "; // Data is printed only when it is not null

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
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

Node *inOrderToBST(int s, int e, vector<int> &inOrderVal)
{
    // Base Case
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    Node *root = new Node(inOrderVal[mid]);
    root->left = inOrderToBST(s, mid - 1, inOrderVal);
    root->right = inOrderToBST(mid + 1, e, inOrderVal);
    return root;
}

Node *BalancedBST(Node *root)
{
    vector<int> inOrderVal;
    // Store inOrder -> sorted values in vector
    inOrder(root, inOrderVal);

    return inOrderToBST(0, inOrderVal.size() - 1, inOrderVal);
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    buildTree(root);

    root = BalancedBST(root);

    levelOrderTraversal(root);
    return 0;
}