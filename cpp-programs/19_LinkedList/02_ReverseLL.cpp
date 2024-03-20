// Reverse a linkedlist using interative and recursive approach
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// Insert End
void insertEnd(node *&head, int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

// Print
void print(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

// Reverse (Iterative)
node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;

        // Recerse the link
        currptr->next = prevptr;

        // Update
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

node *reverseRecursive(node *&head)
{
    if (head->next == NULL)
    {
        return head;
    }

    node *newHead = reverseRecursive(head->next);

    // swap the link
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    node *head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    insertEnd(head, 6);

    print(head);

    node *newHead = reverseRecursive(head);
    print(newHead);
    return 0;
}