// Minimum to burn a tree
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

// Create mapping
// return target node
node *createMapping(node *root, map<node *, node *> &nodeToParent, int target)
{
    node *result = NULL;
    queue<node *> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        if (front->data == target)
        {
            result = front;
        }

        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return result;
}

int burnTree(node *targetNode, map<node *, node *> &nodeToParent)
{
    map<node *, bool> visited;
    queue<node *> q;

    q.push(targetNode);
    visited[targetNode] = true;

    int time = 0;
    while (!q.empty())
    {
        bool flag = false;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            // Process neighbouring nodes
            node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right])
            {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if (flag)
        {
            time++;
        }
    }
    return time;
}

int minTimeToBurn(node *root, int target)
{
    // Algo:
    // Step 1: Create node to parent mapping
    // Step 2: Find target node

    map<node *, node *> nodeToParent;
    node *targetNode = createMapping(root, nodeToParent, target);

    // Step 3: Burn the tree in minimum time
    int time = burnTree(targetNode, nodeToParent);

    return time;
}

int main()
{
    node *root = NULL;
    buildTreeLOT(root);

    int target;
    cout << "Enter Target: ";
    cin >> target;

    int time = minTimeToBurn(root, target);
    cout << "Min Time to Burn the Tree = " << time << endl;
    return 0;
}