// Flatten a tree into a Linked List
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

void flatten(node *root)
{
    node *curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            // Find InOrder Predecessor of curr
            node *pre = curr->left;
            while (pre->right != NULL)
            {
                pre = pre->right;
            }
            // Point InOrder Predecessor of curr to curr->right
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->right;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *root = NULL;
    buildTreeLOT(root);

    flatten(root);
    printLL(root);
    return 0;
}