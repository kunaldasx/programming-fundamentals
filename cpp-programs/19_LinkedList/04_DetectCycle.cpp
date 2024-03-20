// Detect and remove cycle
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

void makeCycle(node *&head, int pos)
{
    node *curr = head;
    node *startNode;

    while (curr->next != NULL)
    {
        pos--;
        if (pos == 0)
        {
            startNode = curr;
        }
        curr = curr->next;
    }
    curr->next = startNode;
}

bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    slow = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
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
    insertEnd(head, 8);
    insertEnd(head, 9);
    insertEnd(head, 10);
    insertEnd(head, 11);
    insertEnd(head, 12);

    print(head);

    cout << detectCycle(head) << endl;
    makeCycle(head, 6);

    cout << detectCycle(head) << endl;

    removeCycle(head);

    cout << detectCycle(head) << endl;

    print(head);
    return 0;
}