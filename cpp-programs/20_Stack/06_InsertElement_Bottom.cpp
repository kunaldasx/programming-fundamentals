// Insert element at the bottom of a stack
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

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    insertAtBot(s, 7);

    while (!s.empty())
    {
        int num = s.top();
        s.pop();
        cout << num << endl;
    }
    return 0;
}