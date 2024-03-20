// Tower of Hanoi
#include <iostream>
using namespace std;

void towerofhanoi(int n, char src, char help, char dest)
{

    if (n == 0)
    {
        return;
    }

    towerofhanoi(n - 1, src, dest, help); // Move n-1 disks from source to helper

    cout << "Move " << n << " from " << src << " to " << dest << endl; // Move nth disk from source to destination

    towerofhanoi(n - 1, help, src, dest); // Move n-1 disks from helper to destination
}

int main()
{
    int n;
    cin >> n;

    towerofhanoi(n, 'A', 'B', 'C');
    return 0;
}