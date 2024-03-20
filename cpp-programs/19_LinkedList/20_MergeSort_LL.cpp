// Merge sort in a linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
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

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node *findMid(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    Node *result = new Node(-1);
    Node *curr = result;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            curr->next = left;
            curr = left;
            left = left->next;
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
        left = left->next;
    }

    while (right != NULL)
    {
        curr->next = right;
        curr = right;
        right = right->next;
    }

    return result->next;
}

Node *mergeSort(Node *head)
{
    // Base condition
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // Break the list into 2 halves
    Node *mid = findMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    // Recursive calls
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the 2 halves
    Node *result = merge(left, right);

    return result;
}

int main()
{
    Node *head = NULL;
    insertEnd(head, 5);
    insertEnd(head, 2);
    insertEnd(head, -1);
    insertEnd(head, 3);
    insertEnd(head, 0);

    Node *newHead = mergeSort(head);
    print(newHead);

    return 0;
}
