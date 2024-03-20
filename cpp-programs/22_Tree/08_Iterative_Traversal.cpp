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

// Iterative in-order traversal
void inorder(node *root)
{
    node *curr = root;
    stack<node *> s;

    while (curr != NULL || s.empty() == false)
    {
        // Reach the left most node
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        // Curr must be NULL at this point
        curr = s.top();
        s.pop();

        // Print the current node
        cout << curr->data << " ";

        // Now visit the right node
        curr = curr->right;
    }
    cout << endl;
}

// Iterative pre-order traversal
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<node *> s;
    s.push(root);

    while (!s.empty())
    {

        // Pop the node from the stack and print it
        node *curr = s.top();
        s.pop();

        // Print the current child
        cout << curr->data << " ";

        // Right child must be pushed first so that the left child is processes first
        if (curr->right)
        {
            s.push(curr->right);
        }

        // Push the left child
        if (curr->left)
        {
            s.push(curr->left);
        }
    }
    cout << endl;
}

// Iterative post order traversal
void postorder(node *root)
{
    stack<node *> s;
    node *curr = root;

    while (curr != NULL || !s.empty())
    {
        // Traverse to the leftmost child of the tree
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            // At this point curr is NULL, So we shift to the right child
            node *temp = s.top()->right;
            if (temp == NULL)
            {
                // If left and right child both are NULL
                temp = s.top();
                s.pop();
                cout << temp->data << " ";

                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    cout << temp->data << " ";
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    cout << endl;
}

// Reverse level order traversal
void reverseLevelOrder(node *root)
{
    stack<node *> s;
    queue<node *> q;
    q.push(NULL);
    q.push(root);

    // Instead of printing the node we push the node to stack
    // Right subtree is visited before left subtree
    while (!q.empty())
    {
        node *curr = q.front();
        q.pop();
        s.push(curr);

        if (curr == NULL && !q.empty())
        {
            // Queue still has some child nodes
            q.push(NULL);
        }
        else if (curr != NULL)
        {
            // Right child
            if (curr->right)
            {
                q.push(curr->right);
            }

            // Left child
            if (curr->left)
            {
                q.push(curr->left);
            }
        }
    }

    // Now pop all the items from the stack and print them

    s.pop(); // Since the stack top will be NULL
    while (!s.empty())
    {
        node *curr = s.top();
        s.pop();

        // Stack top is NULL. Then it means we have completed one level. So print a next line
        if (curr == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << curr->data << " ";
        }
    }
}

int main()
{
    node *root = NULL;
    buildTreeLOT(root);

    reverseLevelOrder(root);
    return 0;
}