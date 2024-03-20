// Doubly LinkedList
#include <iostream>
using namespace std;

int n = 0;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
        n++;
    }
};

void insertBeg(node *&head, int val)
{
    node *newNode = new node(val);

    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

void insertEnd(node *&head, int val)
{
    if (head == NULL)
    {
        insertBeg(head, val);
        return;
    }

    node *newNode = new node(val);
    node *curr = head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;
}

void insert(node *&head, int val, int pos)
{

    if (pos < 1 || pos > n + 1) // including curr
    {
        std::cout << "Invalid Position!" << std::endl;
        return;
    }

    if (head == NULL || pos == 1)
    {
        insertBeg(head, val);
        return;
    }
    node *curr = head;

    node *newNode = new node(val);
    pos -= 2;
    while (pos--)
    {
        curr = curr->next;
    }

    // Insert the new node

    // Link with the right node
    newNode->next = curr->next;
    curr->next->prev = newNode;

    // Link with the left node
    curr->next = newNode;
    newNode->prev = curr;
}

void remove(node *&head, int pos)
{
    if (pos < 1 || pos > n || head == NULL) // including curr
    {
        std::cout << "Invalid Position!" << std::endl;
        return;
    }

    if (head->next == NULL || pos == 1)
    {
        node *todelete = head;
        head = head->next;
        head->prev = NULL;
        n--;

        delete todelete;
        return;
    }

    node *curr = head;
    int count = 1;
    while (curr != NULL && count != pos)
    {
        curr = curr->next;
        count++;
    }

    // Remove the right and left links
    curr->prev->next = curr->next;
    if (curr->next != NULL)
    {
        curr->next->prev = curr->prev;
    }

    delete curr;
    n--;
}

void print(node *&head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    insertBeg(head, 7);
    print(head);
    insert(head, 10, 3);
    print(head);

    remove(head, 3);
    print(head);

    remove(head, 1);
    print(head);
    return 0;
}