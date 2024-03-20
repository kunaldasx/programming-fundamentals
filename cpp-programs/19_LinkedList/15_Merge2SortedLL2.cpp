// Merge two sorted linkedlist -> 2
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

node *helper(node *first, node *second)
{
    // First list has only one element
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    node *curr1 = first;
    node *next1 = curr1->next;
    node *curr2 = second;
    node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && curr2->data <= next1->data)
        {
            // Add node in between first list
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // upadte pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // Update curr1 and next1
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

node *merge(node *first, node *second)
{
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }

    if (first->data <= second->data)
    {
        return helper(first, second);
    }
    else
    {
        return helper(second, first);
    }
}

int main()
{
    node *first = NULL;
    insertEnd(first, 7);
    // insertEnd(first, 8);
    // insertEnd(first, 10);

    node *second = NULL;
    insertEnd(second, 1);
    // insertEnd(second, 3);
    // insertEnd(second, 4);
    // insertEnd(second, 6);

    node *head = merge(first, second);
    print(head);
    return 0;
}