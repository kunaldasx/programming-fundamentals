// Merge K Sorted Linked Lists
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

// Insert End
void insertEnd(Node<int> *&head, int data)
{
    Node<int> *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node<int> *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
}

// Print
void print(Node<int> *head)
{
    Node<int> *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

class compare
{
public:
    bool operator()(Node<int> *a, Node<int> *b)
    {
        return a->data > b->data;
    }
};

Node<int> *mergeKSortedLL(vector<Node<int> *> &kLinkedLists)
{
    priority_queue<Node<int> *, vector<Node<int> *>, compare> minHeap;

    int k = kLinkedLists.size();
    if (k == 0)
    {
        return NULL;
    }

    // Step 1: Insert the head of all the k linked lists
    for (int i = 0; i < k; i++)
    {
        if (kLinkedLists[i] != NULL)
        {
            minHeap.push(kLinkedLists[i]);
        }
    }

    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    // Step 2:
    while (minHeap.size() > 0)
    {
        Node<int> *top = minHeap.top();
        minHeap.pop();

        // Update minHeap
        if (top->next != NULL)
        {
            minHeap.push(top->next);
        }

        // Insert into LL
        if (head == NULL)
        {
            // Answer LL is empty
            head = top;
            tail = top;
        }

        else
        {
            // Insert at Linked List
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

int main()
{
    vector<Node<int> *> kLinkedLists;

    int data, k;

    cout << "Enter K: ";
    cin >> k;
    Node<int> *head[k];

    for (int i = 0; i < k; i++)
    {
        head[i] = NULL;
        cout << "Enter the elements for LL: " << i << endl;
        cin >> data;
        while (data != -1)
        {
            insertEnd(head[i], data);
            cin >> data;
        }
        kLinkedLists.push_back(head[i]);
    }

    Node<int> *ans = mergeKSortedLL(kLinkedLists);

    print(ans);
    return 0;
}