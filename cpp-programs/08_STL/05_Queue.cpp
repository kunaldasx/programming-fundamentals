// Queue
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;

    q.push("Ram");
    q.push("Shradha");
    q.push("Ajay");

    cout << "Size: " << q.size() << endl;

    cout << "First Element: " << q.front() << endl;

    q.pop();
    cout << "First Element: " << q.front() << endl;
    return 0;
}