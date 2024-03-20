// Implementation of 2 stacks in one Array
#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    void push1(int data)
    {
        if (top2 - top1 > 1)
        {
            arr[++top1] = data;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void push2(int data)
    {
        if (top2 - top1 > 1)
        {
            arr[--top2] = data;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop1()
    {
        if (top1 >= 0)
        {
            cout << "Pop element is: " << arr[top1--] << endl;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    void pop2()
    {
        if (top2 < size)
        {
            cout << "Pop element is: " << arr[top2++] << endl;
        }
        else
        {
            cout << "Stack underflow" << endl;
        }
    }

    int peek1()
    {
        if (top1 >= 0)
        {
            return arr[top1];
        }
        return -1;
    }

    int peek2()
    {
        if (top2 < size)
        {
            return arr[top2];
        }
        return -1;
    }

    bool isEmpty1()
    {
        if (top1 == -1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty2()
    {
        if (top2 == size)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Stack stack(5);
    stack.push1(22);
    stack.push1(43);
    stack.push1(44);

    stack.push2(35);
    stack.push2(25);

    cout << stack.peek1() << endl;
    cout << stack.peek2() << endl;

    stack.pop1();
    cout << stack.peek1() << endl;

    stack.pop2();
    stack.pop2();

    cout << stack.isEmpty2() << endl;

    return 0;
}