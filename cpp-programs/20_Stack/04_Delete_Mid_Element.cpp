// Delete middle element from a stack
#include <iostream>
#include <stack>
using namespace std;

void deleteMid(stack<int> &inputStack, int count, int size)
{
    // Base condition
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int data = inputStack.top();
    inputStack.pop();

    // Recursive call
    deleteMid(inputStack, count + 1, size);

    inputStack.push(data);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    deleteMid(s, 0, s.size());

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}