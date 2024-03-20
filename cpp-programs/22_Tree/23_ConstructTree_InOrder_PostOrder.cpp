// Construct tree from InOrder and PostOrder
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

node *solve(int inOrder[], int postOrder[], int &postOrderIndex, int inOrderStart, int inOrderEnd, int size, map<int, int> nodeToIndex)
{
    // Base Condition
    if (postOrderIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // Create a root node for element
    int element = postOrder[postOrderIndex--];
    node *root = new node(element);

    // Find element's index in inOrder
    int pos = nodeToIndex[element];

    // Recursion calls
    // In case of [PostOrder ans InOrder] we first build the right subtree
    root->right = solve(inOrder, postOrder, postOrderIndex, pos + 1, inOrderEnd, size, nodeToIndex);
    root->left = solve(inOrder, postOrder, postOrderIndex, inOrderStart, pos - 1, size, nodeToIndex);

    return root;
}

node *bulidtree(int inOrder[], int postOrder[], int size)
{
    int postOrderIndex = size - 1;

    map<int, int> nodeToIndex; // Keeps track of the index of nodes in inOrder
    createMapping(inOrder, nodeToIndex, size);

    node *ans = solve(inOrder, postOrder, postOrderIndex, 0, size - 1, size, nodeToIndex);
    return ans;
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

int main()
{
    node *root = NULL;

    int size;
    cin >> size;
    int inOrder[size];
    int postOrder[size];

    for (int i = 0; i < size; i++)
    {
        cin >> inOrder[i];
    }
    for (int i = 0; i < size; i++)
    {
        cin >> postOrder[i];
    }

    root = bulidtree(inOrder, postOrder, size);

    preOrderTraversal(root);
    cout << endl;
    return 0;
}