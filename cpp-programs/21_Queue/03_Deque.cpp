// Double Ended Queue
#include <iostream>
using namespace std;

class myDeque
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    myDeque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (front != 0 && rear == (front - 1) % (size - 1)))
        {
            return true;
        }
        return false;
    }

    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    // Push Front
    void push_front(int data)
    {
        // Check Full
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }

    void push_back(int data)
    {
        // Check Full
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = data;
    }

    int pop_front()
    {
        if (isEmpty())
        {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = rear = -1; // Single element is present
        }
        else if (front == size - 1)
        {
            front = 0; // To maintain cyclic nature
        }
        else
        {
            front++; // Normal flow
        }

        return ans;
    }

    int pop_back()
    {
        if (isEmpty())
        {
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        {
            front = rear = -1; // Single element is present
        }
        else if (rear == 0)
        {
            rear = size - 1; // To maintain cyclic nature
        }
        else
        {
            rear--; // Normal flow
        }

        return ans;
    }
};

int main()
{
    myDeque dq(5);
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(25);

    dq.push_front(30);

    dq.push_back(100);
    cout << dq.isFull() << endl;

    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl;

    dq.pop_front();
    dq.pop_back();

    cout << dq.getFront() << endl;
    cout << dq.getRear() << endl;

    dq.pop_front();
    dq.pop_front();
    dq.pop_back();

    cout << dq.isEmpty() << endl;

    return 0;
}