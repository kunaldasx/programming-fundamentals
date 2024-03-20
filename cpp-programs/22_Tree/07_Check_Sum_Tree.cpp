// Check Sum Tree
// N = L + R
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

pair<bool, int> isSumTree(node *root)
{
    // Base Case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    // first --- isSumTree
    // second --- sum

    pair<bool, int> left = isSumTree(root->left);
    pair<bool, int> right = isSumTree(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool curr = root->data == (left.second + right.second);

    pair<bool, int> ans;

    if (leftAns && rightAns && curr)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

int main()
{
    node *root = NULL;
    buildTreeLOT(root);

    pair<int, int> ans = isSumTree(root);
    if (ans.first)
    {
        cout << "Sum Tree" << endl;
    }
    else
    {
        cout << "Not Sum Tree" << endl;
    }

    return 0;
}