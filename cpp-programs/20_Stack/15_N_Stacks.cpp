// N stacks in a single array
#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;

    int n, s;

    int freespot;

public:
    // Initialise your data structure
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[n];
        top = new int[s];
        next = new int[n];

        // Initialize top
        for (int i = 0; i < s; i++)
        {
            top[i] = -1;
        }

        // Initialize next
        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }
        // Update last index of next to -1
        next[n - 1] = -1;

        // Initialise freespot
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack
    void push(int x, int m)
    {
        // Check for overflow
        if (freespot == -1)
        {
            cout << "Stack Overflow." << endl;
            return;
        }

        // Find index
        int index = freespot;

        // Insert element into array
        arr[index] = x;

        // Update freespot
        freespot = next[index];

        // Update next
        next[index] = top[m - 1];

        // Update top
        top[m - 1] = index;
    }

    // Pops top element from Mth stack
    void pop(int m)
    {
        // Check for underflow
        if (top[m - 1] == -1)
        {
            cout << "Stack Underflow." << endl;
            return;
        }

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;

        cout << "Poped element is: " << arr[index] << endl;
    }

    void print(int m)
    {
        while (top[m - 1] != -1)
        {
            int index = top[m - 1];
            top[m - 1] = next[index];
            next[index] = freespot;
            freespot = index;

            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

int main()
{
    NStack ns(6, 3);
    ns.push(10, 1);
    ns.push(20, 1);
    ns.push(25, 1);

    ns.push(100, 2);
    ns.push(200, 2);

    ns.push(74, 1);

    ns.pop(1);
    ns.pop(2);
    ns.print(1);
    ns.print(2);
    return 0;
}
