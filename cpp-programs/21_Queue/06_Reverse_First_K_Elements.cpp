// Reverse first k elements of Queue
#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    // Pop First k elements from queue and push into stack
    stack<int> s;

    for (int i = 0; i < k; i++)
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    // fetch from stack and push into queue
    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }

    // Fetch frist n-k elements from Queue and push_back
    for (int i = 0; i < q.size() - k; i++)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }
    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q = modifyQueue(q, 3);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}