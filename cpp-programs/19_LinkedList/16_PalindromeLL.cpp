// Check if a Linked List is palindrome
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

node *getMid(node *head)
{
    node *slow = head;
    node *fast = head->next; // Gives 3 when length is 7

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

node *reverseList(node *&head)
{
    if (head->next == NULL)
    {
        return head;
    }

    node *newHead = reverseList(head->next);

    // swap the link
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

bool checkPalindrome(node *head)
{
    if (head->next == NULL)
    {
        return true;
    }

    // Find Mid
    node *mid = getMid(head);

    // Reverse the 2nd half of LL
    mid->next = reverseList(mid->next);

    // Compare both halves
    node *curr1 = head;
    node *curr2 = mid->next;
    while (curr2 != NULL)
    {
        if (curr1->data != curr2->data)
        {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    // // Repeat step 2
    mid->next = reverseList(mid->next);

    return true;
}

int main()
{
    node *head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 3);
    insertEnd(head, 2);
    insertEnd(head, 1);

    if (checkPalindrome(head))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    print(head);
    return 0;
}