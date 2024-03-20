// Construct tree from InOrder and PreOrder
#include <iostream>
#include <map>
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

void createMapping(int inOrder[], map<int, int> &nodeToIndex, int size)
{
    for (int i = 0; i < size; i++)
    {
        nodeToIndex[inOrder[i]] = i;
    }
}

node *solve(int inOrder[], int preOrder[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int size, map<int, int> nodeToIndex)
{
    // Base Condition
    if (preOrderIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // Create a root node for element
    int element = preOrder[preOrderIndex++];
    node *root = new node(element);

    // Find element's index in inOrder
    int pos = nodeToIndex[element];

    // Recursion calls
    root->left = solve(inOrder, preOrder, preOrderIndex, inOrderStart, pos - 1, size, nodeToIndex);
    root->right = solve(inOrder, preOrder, preOrderIndex, pos + 1, inOrderEnd, size, nodeToIndex);

    return root;
}

node *bulidtree(int inOrder[], int preOrder[], int size)
{
    int preOrderIndex = 0;

    map<int, int> nodeToIndex; // Keeps track of the index of nodes in inOrder
    createMapping(inOrder, nodeToIndex, size);

    node *ans = solve(inOrder, preOrder, preOrderIndex, 0, size - 1, size, nodeToIndex);
    return ans;
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

    int size;
    cin >> size;
    int inOrder[size];
    int preOrder[size];

    for (int i = 0; i < size; i++)
    {
        cin >> inOrder[i];
    }
    for (int i = 0; i < size; i++)
    {
        cin >> preOrder[i];
    }

    root = bulidtree(inOrder, preOrder, size);

    postOrderTraversal(root);
    cout << endl;
    return 0;
}