// Add two numbers represented by a linked list
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// Insert End
void insertEnd(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node *reverseLL(Node *&head)
{
    if (head->next == NULL)
    {
        return head;
    }

    Node *newHead = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

Node *add(Node *first, Node *second)
{
    Node *ans = NULL;
    int carry = 0;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        int sum = carry + val1 + val2;

        int digit = sum % 10;
        insertEnd(ans, digit);

        carry = sum / 10;

        if (first != NULL)
            first = first->next;
        if (second != NULL)
            second = second->next;
    }
    return ans;
}

int main()
{
    Node *first = NULL;
    insertEnd(first, 3);
    insertEnd(first, 4);
    insertEnd(first, 5);

    Node *second = NULL;
    insertEnd(second, 4);
    insertEnd(second, 5);

    // Reverse both LL
    first = reverseLL(first);
    second = reverseLL(second);

    // Add the LL
    Node *ans = add(first, second);

    // Reverse both LL again
    first = reverseLL(first);
    second = reverseLL(second);

    // Reverse ans LL
    ans = reverseLL(ans);
    print(ans);
    return 0;
}