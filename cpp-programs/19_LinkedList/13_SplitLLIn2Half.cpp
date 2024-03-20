// Divide a ll in 2 halfs
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

// Insert Begining
void insertBeg(node *&head, int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Insert End
void insertEnd(node *&head, int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        insertBeg(head, data);
        return;
    }

    node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    newNode->next = head;
    curr->next = newNode;
}

// Print
void print(node *head)
{
    node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

node *divide(node *head)
{
    node *fast = head;
    node *slow = head;

    while (fast->next != head)
    {
        if (fast->next->next == head)
        {
            fast = fast->next;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    // For 1st half
    node *newHead = slow->next;
    slow->next = head;

    // For 2nd half
    fast->next = newHead;

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

    node *newHead = divide(head);
    print(head);
    print(newHead);

    return 0;
}