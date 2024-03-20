// Find Kth smallest element in a BST
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

int kthSmallest(Node *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    // InOrder Traversal

    // L
    int left = kthSmallest(root->left, i, k);

    if (left != -1)
    {
        return left;
    }

    // N
    i++;
    if (i == k)
    {
        return root->data;
    }

    // R
    return kthSmallest(root->right, i, k);
}

// Kth smallest element in a BST using Morris Traversal
int kthSmallest_Morris(Node *root, int k)
{
    // Base Condition
    if (root == NULL)
    {
        return -1;
    }

    int i = 0;
    Node *curr = root;
    Node *pre = NULL; // Predecessor
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            i++;
            int ans = curr->data;
            curr = curr->right;
            if (i == k)
            {
                return ans;
            }
        }
        else
        {
            // Find the inOrder predecessor of curr
            pre = curr->left;
            while (pre->right != NULL && pre->right->data != curr->data)
            {
                pre = pre->right;
            }

            // Make curr as the right child of its InOrder predecessor
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }

            // Reverse the changes made in the above 'if' statement
            else
            {
                pre->right = NULL;
                i++;
                int ans = curr->data;
                curr = curr->right;
                if (i == k)
                {
                    return ans;
                }
            }
        }
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    buildTree(root);

    int k;
    cout << "Enter K: ";
    cin >> k;
    int i = 0;
    cout << kthSmallest(root, i, k) << endl;
    cout << kthSmallest_Morris(root, k) << endl;
    return 0;
}