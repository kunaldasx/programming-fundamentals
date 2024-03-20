// Check if the brackets in a string are redundant or not
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isRedundant(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            bool redundant = true;
            while (s.top() != '(')
            {
                char top = s.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    redundant = false;
                }
                s.pop();
            }
            s.pop();
            if (redundant == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string str = "(a+(c*d))";

    cout << isRedundant(str) << endl;
    return 0;
}