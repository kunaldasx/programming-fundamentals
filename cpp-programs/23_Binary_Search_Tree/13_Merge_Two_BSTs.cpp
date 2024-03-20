// Merge two BSTs
// Time --- O(M + N)
// Space --- O(M + N)
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

// Save the InOrder traversal of both the BSTs
void storeInOrder(Node *root, vector<int> &inOrder)
{
    if (root == NULL)
    {
        return;
    }

    storeInOrder(root->left, inOrder);
    inOrder.push_back(root->data);
    storeInOrder(root->right, inOrder);
}

// Merge two sorted vectors
vector<int> mergeVector(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0, k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }

    while (i < a.size())
    {
        ans[k++] = a[i++];
    }

    while (j < b.size())
    {
        ans[k++] = b[j++];
    }

    return ans;
}

// InOrder to BST
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

// Merge two BSTs
Node *mergeBST(Node *root1, Node *root2)
{
    // Step 1: Store InOrder
    vector<int> bst1, bst2;
    storeInOrder(root1, bst1);
    storeInOrder(root2, bst2);

    // Step 2: Merge the two vector in sorted order
    vector<int> mergedVector = mergeVector(bst1, bst2);

    // Step 3: Create a BST from the merged vector
    int s = 0, e = mergedVector.size() - 1;
    return inOrderToBST(s, e, mergedVector);
}

int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;

    cout << "Enter data to create BST1" << endl;
    buildTree(root1);
    cout << "Enter data to create BST2" << endl;
    buildTree(root2);

    Node *root = mergeBST(root1, root2);
    levelOrderTraversal(root);
    return 0;
}