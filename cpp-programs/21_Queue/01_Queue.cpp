#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue()
    {
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // Enqueue
    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full.";
            return;
        }
        arr[rear++] = data;
    }

    // Dequeue
    int dequeue()
    {
        if (front == rear)
        {
            return -1;
        }

        int ans = arr[front];
        arr[front++] = -1;

        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        return front;
    }

    // Front
    int qfront()
    {
        if (front == rear)
        {
            return -1;
        }
        return arr[front];
    }

    // Check empty
    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(74);

    cout << q.qfront() << endl;

    cout << q.dequeue() << endl;

    cout << q.qfront() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}