// Sort a Stack
#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &inputStack, int num)
{
    if (inputStack.empty() || inputStack.top() < num)
    {
        inputStack.push(num);
        return;
    }

    int n = inputStack.top();
    inputStack.pop();

    insertSorted(inputStack, num);

    inputStack.push(n);
}

void sortStack(stack<int> &inputStack)
{
    if (inputStack.empty())
    {
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // Recursive call
    sortStack(inputStack);

    insertSorted(inputStack, num);
}

int main()
{
    stack<int> s;

    s.push(-2);
    s.push(3);
    s.push(0);
    s.push(4);
    s.push(9);

    sortStack(s);

    while (!s.empty())
    {
        int num = s.top();
        s.pop();
        cout << num << endl;
    }
    return 0;
}