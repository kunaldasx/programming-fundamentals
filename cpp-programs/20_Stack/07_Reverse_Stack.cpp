// Reverse Stack
#include <iostream>
#include <stack>
using namespace std;

void insertAtBot(stack<int> &inputStack, int data)
{
    if (inputStack.empty())
    {
        inputStack.push(data);
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // Recursive call
    insertAtBot(inputStack, data);

    inputStack.push(num);
}

void reverseStack(stack<int> &inputStack)
{
    // Base Condition
    if (inputStack.empty())
    {
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // Recursive Call
    reverseStack(inputStack);

    insertAtBot(inputStack, num);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);

    while (!s.empty())
    {
        int num = s.top();
        s.pop();
        cout << num << endl;
    }

    return 0;
}