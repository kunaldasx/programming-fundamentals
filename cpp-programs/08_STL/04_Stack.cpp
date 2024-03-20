// Stack
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<string> s;

    s.push("Ram");
    s.push("Shradha");
    s.push("Ajay");

    cout << "Top Element: " << s.top() << endl;

    s.pop();
    cout << "Top Element: " << s.top() << endl;

    cout << s.size() << endl;

    cout << s.empty() << endl;
    return 0;
}