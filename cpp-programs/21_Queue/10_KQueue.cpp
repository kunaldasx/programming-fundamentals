// Implement K Queues in an array
#include <bits/stdc++.h>
using namespace std;

class KQueue
{
public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

    KQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];

        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    void enqueue(int data, int qn)
    {
        // Check Qverflow
        if (freeSpot == -1)
        {
            cout << "Queue Overflow." << endl;
            return;
        }

        // Find free index
        int index = freeSpot;

        // Update freeSpot
        freeSpot = next[index];

        // Check whether it's the first element for the Queue
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            // Link new element to the prev element
            next[rear[qn - 1]] = index;
        }

        // Update next
        next[index] = -1;

        // Update rear
        rear[qn - 1] = index;

        // Push element
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        // Check Underflow
        if (front[qn - 1] == -1)
        {
            cout << "Queue Underflow." << endl;
            return -1;
        }

        // Find index to pop
        int index = front[qn - 1];

        // Update front
        front[qn - 1] = next[index];

        // Manage the new free slot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main()
{
    KQueue q(10, 3);

    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    return 0;
}