// Find Intersection point of 2 Linked List
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

void intersect(node *&head1, node *&head2, int pos)
{
    node *ptr1 = head1;
    node *ptr2 = head2;

    pos--;
    while (pos--)
    {
        ptr1 = ptr1->next;
    }

    while (ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
    }

    ptr2->next = ptr1;
}

int findIntersection(node *&head1, node *&head2)
{
    int n1 = getSize(head1);
    int n2 = getSize(head2);

    node *ptr1;
    node *ptr2;
    int d;

    if (n1 > n2)
    {
        d = n1 - n2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = n2 - n1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d--)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main()
{
    node *head1 = NULL;
    insertEnd(head1, 1);
    insertEnd(head1, 2);
    insertEnd(head1, 3);
    insertEnd(head1, 4);
    insertEnd(head1, 5);
    insertEnd(head1, 6);

    node *head2 = NULL;
    insertEnd(head2, 9);
    insertEnd(head2, 10);

    intersect(head1, head2, 5);
    print(head1);
    print(head2);

    cout << findIntersection(head1, head2) << endl;

    return 0;
}