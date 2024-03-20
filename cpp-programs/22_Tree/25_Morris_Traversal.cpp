// Morris Traversal
// Time --- O(n)
// Space --- O(1)
#include <iostream>
#include <queue>
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

// Function to traverse the binary tree without recursion and without stack
void MorrisTraversal(node *root)
{
    // Base Condition
    if (root == NULL)
    {
        return;
    }

    node *curr = root;
    node *pre = NULL; // Predecessor node
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            // Find the InOrder predecessor of curr
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
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
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    node *root = NULL;
    buildTreeLOT(root);

    MorrisTraversal(root);
    cout << endl;
    return 0;
}
