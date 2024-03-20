// Clone a linked list with random pointers
#include <iostream>
#include <map>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *random;

    node(int data)
    {
        this->data = data;
        next = NULL;
        random = NULL;
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

// Insert random pointers
void insertRandom(node *head, int si, int ei)
{
    int counter = 1;
    node *curr = head;
    node *src = NULL;
    node *des = NULL;
    while (curr != NULL)
    {
        if (counter == si)
        {
            src = curr;
        }

        if (counter == ei)
        {
            des = curr;
        }
        curr = curr->next;
        counter++;
    }
    src->random = des;
}

// Clone List
node *cloneList(node *head)
{
    // Step 1: Create a clone list
    node *cloneHead = NULL;
    node *curr = head;

    while (curr != NULL)
    {
        insertEnd(cloneHead, curr->data);
        curr = curr->next;
    }

    // Step 2: Add cloneNodes in between original list
    node *originalNode = head;
    node *cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        node *nextNode = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = nextNode;

        nextNode = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = nextNode;
    }

    // Step 3: Copy random pointers
    curr = head;

    while (curr != NULL)
    {
        if (curr->next != NULL)
        {
            curr->next->random = curr->random ? curr->random->next : curr->random;
        }
        curr = curr->next->next;
    }

    // Step 4: Revert changes done in step
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if (originalNode != NULL)
        {
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }

    // Step 5: return answer
    return cloneHead;
}

// Print
void print(node *head)
{
    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    cout << curr->random->data << endl;
}

int main()
{
    node *head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    insertRandom(head, 1, 3);
    insertRandom(head, 3, 5);
    insertRandom(head, 5, 2);
    insertRandom(head, 4, 3);
    insertRandom(head, 2, 1);

    node *cloneHead = cloneList(head);
    print(cloneHead);
    cout << cloneHead->random->data << endl;

    return 0;
}