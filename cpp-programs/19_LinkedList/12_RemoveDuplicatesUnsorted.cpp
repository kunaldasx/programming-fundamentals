// Remove Duplicates from an unsorted LinkedList
#include <iostream>
#include <vector>
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

void removeDuplicates(node *head)
{
    if (head == NULL)
    {
        return;
    }

    node *curr = head;
    vector<bool> visited(10, 0); // Map will work better here
    visited[curr->data] = 1;
    while (curr->next != NULL)
    {
        if (visited[curr->next->data])
        {
            node *todelete = curr->next;
            curr->next = curr->next->next;
            delete todelete;
        }
        else
        {
            visited[curr->next->data] = 1;
            curr = curr->next;
        }
    }
}

int main()
{
    node *head = NULL;
    insertEnd(head, 4);
    insertEnd(head, 7);
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 4);
    insertEnd(head, 3);

    removeDuplicates(head);
    print(head);
    return 0;
}