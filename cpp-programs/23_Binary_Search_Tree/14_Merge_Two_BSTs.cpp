// Merge two BSTs
// Time --- O(M + N)
// Space --- O(H1 + H2)
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

// Convert BST into Doubly Linked List
void convertIntoDLL(Node *root, Node *&head)
{
    // Base Condition
    if (root == NULL)
    {
        return;
    }

    // Process the right sub-tree
    convertIntoDLL(root->right, head);

    // Process the root node
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;

    // Process the left sub-tree
    convertIntoDLL(root->left, head);
}

// Merge the two Doubly Linked Lists into one
Node *mergeDLL(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;

                // Update
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;

                // Update
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;

        // Update
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;

        // Update
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

// Count Nodes in a Doubly Linked List
int countNodes(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->right;
    }
    return count;
}

// Create a BST from the merged Doubly Linked List
Node *sortedDLLToBST(Node *&head, int n)
{
    // Base Condition
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    // Create the left sub-tree
    Node *left = sortedDLLToBST(head, n / 2);

    // Connect the root with the left sub-tree
    Node *root = head;
    root->left = left;
    head = head->right;

    // Connect the
    root->right = sortedDLLToBST(head, n - n / 2 - 1);
    return root;
}

// Main
Node *mergeBST(Node *root1, Node *root2)
{
    // Step 1 : Convert BST into sorted Doubly Linked List in-place
    Node *head1 = NULL;
    convertIntoDLL(root1, head1);

    Node *head2 = NULL;
    convertIntoDLL(root2, head2);

    // Step 2: Merge two Sorted Doubly Linked List
    Node *head = mergeDLL(head1, head2);

    // Step 3: Convert Sorted Doubly Linked List To BST
    return sortedDLLToBST(head, countNodes(head));
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