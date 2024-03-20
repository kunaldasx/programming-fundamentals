// Priority Queue
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> p; // Max Heap

    priority_queue<int, vector<int>, greater<int>> q; // Min Heap

    p.push(1);
    p.push(3);
    p.push(5);
    p.push(2);
    p.push(4);

    int size = p.size();
    cout << "Size: " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;

    q.push(1);
    q.push(3);
    q.push(5);
    q.push(2);
    q.push(4);

    int n = q.size();
    cout << "Size: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;

    cout << q.empty() << endl;
    return 0;
}