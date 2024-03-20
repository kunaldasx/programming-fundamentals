// Ineterleave first half of the queue with second half
#include <bits/stdc++.h>
using namespace std;

queue<int> interleave(queue<int> q)
{
    int n = q.size();
    if (n % 2 != 0)
    {
        cout << "Input even number of elements." << endl;
        return q;
    }

    int half = n / 2;

    // Push the first half elements of Queue into Stack
    stack<int> s;
    for (int i = 0; i < half; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // Push the elements from stack into Queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // Pop the first half elements of Queue and Push back
    for (int i = 0; i < half; i++)
    {
        q.push(q.front());
        q.pop();
    }

    // Push the first half elements of Queue into Stack again
    for (int i = 0; i < half; i++)
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        // Push from Stack
        q.push(s.top());
        s.pop();

        // Pop from Queue front and Push back
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main()
{
    queue<int> q;
    for (int i = 11; i <= 20; i++)
    {
        q.push(i);
    }

    q = interleave(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}