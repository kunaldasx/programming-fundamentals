// Circular LinkedList
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

// Delete At Head
void deleteAtHead(node *&head)
{
    node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }

    node *todelete = head;
    curr->next = head->next;
    head = head->next;

    delete todelete;
}

// Delete
void deletion(node *&head, int pos)
{
    if (head == NULL || pos == 1)
    {
        deleteAtHead(head);
        return;
    }

    node *curr = head;
    int count = 1;
    while (count != pos - 1)
    {
        curr = curr->next;
        count++;
    }

    node *todelete = curr->next;
    curr->next = curr->next->next;

    delete todelete;
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

    insertBeg(head, 7);
    print(head);

    deletion(head, 7);
    print(head);

    deleteAtHead(head);
    print(head);

    deletion(head, 3);
    print(head);

    deletion(head, 1);
    print(head);
    return 0;
}
