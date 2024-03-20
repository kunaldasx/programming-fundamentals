// Check if Two trees identical
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

// Time --- O(N)
bool isIdentical(node *r1, node *r2)
{
    // Base case
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if (r1 == NULL && r2 != NULL)
    {
        return false;
    }

    if (r1 != NULL && r2 == NULL)
    {
        return false;
    }

    // Here Both are Non NULL
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool curr = r1->data == r2->data;

    if (left && right && curr)
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
    node *r1 = NULL;
    buildTreeLOT(r1);

    node *r2 = NULL;
    buildTreeLOT(r2);

    if (isIdentical(r1, r2))
    {
        cout << "Trees are Identical" << endl;
    }
    else
    {
        cout << "Tree are not Identical" << endl;
    }

    return 0;
}