// Implementation of Stack class using Array
#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int(size);
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            arr[++top] = data;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            cout << "Pop element is: " << arr[top--] << endl;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        return -1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Stack stack(5);
    stack.push(22);
    stack.push(43);
    stack.push(44);

    cout << stack.peek() << endl;

    stack.pop();
    cout << stack.peek() << endl;

    stack.pop();

    cout << stack.isEmpty() << endl;

    return 0;
}