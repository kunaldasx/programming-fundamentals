// Sort 0s 1s and 2s
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

void populate(node *&tail, node *curr)
{
    tail->next = curr;
    tail = curr;
}

void sortList(node *&head)
{
    node *zeroHead = new node(-1);
    node *zeroTail = zeroHead;
    node *oneHead = new node(-1);
    node *oneTail = oneHead;
    node *twoHead = new node(-1);
    node *twoTail = twoHead;

    // Create seperate lists 0s 1s 2s
    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            populate(zeroTail, curr);
        }
        else if (curr->data == 1)
        {
            populate(oneTail, curr);
        }
        else if (curr->data == 2)
        {
            populate(twoTail, curr);
        }
        curr = curr->next;
    }

    // Merge 3 sublists

    // 1s list not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    // 1s list -> empty
    else
    {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // Setup head
    head = zeroHead->next;

    // Delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
}

int main()
{
    node *head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 0);
    insertEnd(head, 2);
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 0);

    sortList(head);
    print(head);
    return 0;
}