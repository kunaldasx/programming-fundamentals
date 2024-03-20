// Creating a binary tree
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Build Tree
node *buildTree(node *root)
{
    cout << "Enter data: ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for the left node of " << data << ": ";
    root->left = buildTree(root->left);

    cout << "Enter data for the right node of " << data << ": ";
    root->right = buildTree(root->right);

    return root;
}

// Build Tree from level order traversal
void buildTreeLOT(node *&root)
{
    queue<node *> q;
    cout << "Enter data for root: ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter data for left node of " << temp->data << ": ";
        int leftNode;
        cin >> leftNode;

        if (leftNode != -1)
        {
            temp->left = new node(leftNode);
            q.push(temp->left);
        }

        cout << "Enter data for right node of " << temp->data << ": ";
        int rightNode;
        cin >> rightNode;

        if (rightNode != -1)
        {
            temp->right = new node(rightNode);
            q.push(temp->right);
        }
    }
}

// Level order Traversal
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
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

// In-order Traversal
void inOrderTraversal(node *root)
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

// Pre-order Traversal
void preOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // NLR (Node Left Right)
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post-order Traversal
void postOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // NLR (Node Left Right)
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;

    // Creating a tree
    // root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // Creating tree from level order traversal input
    buildTreeLOT(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // cout << "Printing the level order traversal output" << endl;
    // levelOrderTraversal(root);

    // cout << "Printing the inorder traversal output" << endl;
    // inOrderTraversal(root);
    // cout << endl;

    // cout << "Printing the preorder traversal output" << endl;
    // preOrderTraversal(root);
    // cout << endl;

    // cout << "Printing the postorder traversal output" << endl;
    // postOrderTraversal(root);
    // cout << endl;

    return 0;
}