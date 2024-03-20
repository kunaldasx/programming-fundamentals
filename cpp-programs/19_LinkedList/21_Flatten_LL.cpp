// Flatten a linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        child = NULL;
    }
};

// Insert End
void insertEnd(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

// Insert Child
void insertChild(Node *head, int data, int n)
{
    Node *newNode = new Node(data);

    Node *curr = head;
    n--;
    while (n--)
    {
        curr = curr->next;
    }

    while (curr->child != NULL)
    {
        curr = curr->child;
    }
    curr->child = newNode;
}

// Print LL
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Print LL with child nodes
void printBranched(Node *head)
{
    while (head != NULL)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->child;
        }
        cout << endl;
        head = head->next;
    }
}

Node *merge(Node *left, Node *right)
{
    Node *result = new Node(-1);
    Node *curr = result;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            curr->next = left;
            curr = left;
            left = left->child;
        }
        else
        {
            curr->next = right;
            curr = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        curr->next = left;
        curr = left;
        left = left->child;
    }

    while (right != NULL)
    {
        curr->next = right;
        curr = right;
        right = right->next;
    }
    return result->next;
}

Node *flattenList(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }

    Node *left = head;
    Node *right = flattenList(head->next);

    Node *result = merge(left, right);

    return result;
}

int main()
{
    Node *head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 4);
    insertEnd(head, 7);
    insertEnd(head, 9);
    insertEnd(head, 20);

    insertChild(head, 2, 1);
    insertChild(head, 3, 1);

    insertChild(head, 5, 2);
    insertChild(head, 6, 2);

    insertChild(head, 8, 3);

    insertChild(head, 12, 4);

    printBranched(head);

    Node *result = flattenList(head);
    print(head);

    return 0;
}
