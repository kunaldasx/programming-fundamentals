// LinkedList
#include <bits/stdc++.h>
// using namespace std;

int size = 0;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
        size++;
    }
};

// Insert Begining
void insertBeg(node *&head, int data)
{
    node *newNode = new node(data);
    newNode->next = head;
    head = newNode;
}

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

// Insert at a particular position
void insert(node *&head, int data, int pos)
{
    if (pos < 1 || pos > size + 1) // including curr
    {
        std::cout << "Invalid Position!" << std::endl;
        return;
    }

    node *newNode = new node(data);
    if (head == NULL || pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    node *curr = head;
    pos -= 2; // In order to get to the position before the required position
    while (pos--)
    {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

// Delete
void deletion(node *&head, int pos)
{
    if (head == NULL || pos < 1 || pos > size)
    {
        std::cout << "Invalid Position!" << std::endl;
        return;
    }

    if (head->next == NULL || pos == 1)
    {
        node *todelete = head;
        head = head->next;

        delete todelete;
        size--;
        return;
    }

    node *curr = head;
    pos -= 2;
    while (pos--)
    {
        curr = curr->next;
    }
    node *todelete = curr->next;
    curr->next = curr->next->next;

    delete todelete;
    size--;
}

// Print
void print(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        std::cout << curr->data << "->";
        curr = curr->next;
    }
    std::cout << "NULL" << std::endl;
}

// Get Size
void getSize()
{
    std::cout << "Size = " << size << std::endl;
}

int main()
{
    node *head = NULL;
    int ch, data, pos;
    while (1)
    {
        std::cout << "Enter Your Choice\nPress 1 for Insert Begining\nPress 2 for Insert End\nPress 3 for Insert\nPress 4 for Print\nPress 5 to Delete\nPress 6 for Size\nPress 0 to Exit\n";
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            std::cout << "Enter Data: ";
            std::cin >> data;
            insertBeg(head, data);
            break;
        case 2:
            std::cout << "Enter Data: ";
            std::cin >> data;
            insertEnd(head, data);
            break;
        case 3:
            std::cout << "Enter Data: ";
            std::cin >> data;
            std::cout << "Enter Position: ";
            std::cin >> pos;
            insert(head, data, pos);
            break;
        case 4:
            print(head);
            break;
        case 5:
            std::cout << "Enter Position: ";
            std::cin >> pos;
            deletion(head, pos);
            break;
        case 6:
            getSize();
            break;
        case 0:
            return 0;
        default:
            std::cout << "Invalid Choice!" << std::endl;
        }
    }
    return 0;
}