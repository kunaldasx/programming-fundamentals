// Append last k nodes at the begining of a linkedlist
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

int getSize(node *head)
{
    int n = 0;
    while (head != NULL)
    {
        head = head->next;
        n++;
    }
    return n;
}

node *kAppend(node *&head, int k)
{
    node *newHead;
    node *newTail;
    node *tail = head;

    int n = getSize(head);
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == n - k)
        {
            newTail = tail;
        }
        if (count == n - k + 1)
        {
            newHead = tail;
        }

        tail = tail->next;
        count++;
    }
    tail->next = head;
    newTail->next = NULL;

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
    insertEnd(head, 7);

    print(head);
    node *newHead = kAppend(head, 3);
    print(newHead);
    return 0;
}