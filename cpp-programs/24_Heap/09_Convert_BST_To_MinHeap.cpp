// Convert a BST into a min heap in which every left child is less than the right child
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

void buildTree(Node *&root)
{
    int data;
    cout << "Enter data: ";
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

// Store the values in vector in InOrder
void storeInOrder(Node *root, vector<int> &inOrder)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    storeInOrder(root->left, inOrder);
    inOrder.push_back(root->data);
    storeInOrder(root->right, inOrder);
}

// Build the Heap from the vector in PreOrder
// N < L < R
void buildHeapFromInorder(Node *&root, vector<int> inOrder, int &idx)
{
    // Base Case
    if (root == NULL || inOrder.empty())
    {
        return;
    }

    root->data = inOrder[idx++];
    buildHeapFromInorder(root->left, inOrder, idx);
    buildHeapFromInorder(root->right, inOrder, idx);
}

// Main
void BSTtoMinHeap(Node *&root)
{
    vector<int> inOrder;
    storeInOrder(root, inOrder);

    int idx = 0;
    buildHeapFromInorder(root, inOrder, idx);
}

int main()
{
    Node *root = NULL;
    buildTree(root);

    BSTtoMinHeap(root);
    levelOrderTraversal(root);
    return 0;
}