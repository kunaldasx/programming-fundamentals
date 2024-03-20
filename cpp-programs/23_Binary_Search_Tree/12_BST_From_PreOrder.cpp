// Create a BST from the given pre Order
#include <iostream>
#include <vector>
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

Node *solve(vector<int> &preOrder, int mini, int maxi, int &idx)
{
    if (idx >= preOrder.size())
    {
        return NULL;
    }

    if (preOrder[idx] < mini || preOrder[idx] > maxi)
    {
        return NULL;
    }

    Node *root = new Node(preOrder[idx++]);
    root->left = solve(preOrder, mini, root->data, idx);
    root->right = solve(preOrder, root->data, maxi, idx);

    return root;
}

Node *preOrderToBST(vector<int> &preOrder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int idx = 0;

    return solve(preOrder, mini, maxi, idx);
}

int main()
{
    Node *root = NULL;

    vector<int> preOrder;
    int data;
    cout << "Enter PreOrder data: ";
    cin >> data;

    while (data != -1)
    {
        preOrder.push_back(data);
        cin >> data;
    }

    root = preOrderToBST(preOrder);
    levelOrderTraversal(root);
    return 0;
}