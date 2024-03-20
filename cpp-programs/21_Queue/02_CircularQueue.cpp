#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int n = 100001)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueue
    void enqueue(int data)
    {
        if (front == (rear + 1) % size)
        {
            cout << "Queue is full." << endl;
            return;
        }

        rear = (rear + 1) % size;
        arr[rear] = data;

        if (front == -1)
        {
            front = 0;
        }
    }

    // Dequeue
    int dequeue()
    {
        // Empty
        if (front == -1)
        {
            return -1;
        }

        int num = arr[rear];

        if (front == rear)
        {
            front = rear = -1;
            return num;
        }

        front = (front + 1) % size;
        return num;
    }

    // Check empty
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    // Check Full
    bool isFull()
    {
        if (front == (rear + 1) % size)
        {
            return true;
        }
        return false;
    }

    void print()
    {
        for (int i = front; i != rear; i = (i + 1) % size)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }

    int qfront()
    {
        if (front == -1)
        {
            return -1;
        }
        return arr[front];
    }
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(74);
    q.enqueue(100);

    q.print();

    q.dequeue();
    q.dequeue();

    q.print();

    q.enqueue(200);
    q.enqueue(700);
    q.print();

    cout << q.isFull() << endl;
    cout << q.isEmpty() << endl;

    cout << q.qfront() << endl;
    return 0;
}