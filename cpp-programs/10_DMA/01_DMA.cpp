// Program to demonstrate DMA
#include <iostream>
using namespace std;

int main()
{
    int a = 4; // Stored in stack;
    cout << a << endl;

    // int *p = new int(); // allocate memory in heap
    // *p = 5;
    // cout << *p << endl;

    // delete (p); // deallocate memory

    // p = new int[4];

    // p[0] = 10;
    // p[1] = 20;
    // p[2] = 30;
    // p[3] = 40;

    // // two ways to print dynamic array
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << p[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < 4; i++)
    // {
    //     cout << *(p + i) << " ";
    // }
    // cout << endl;

    // delete[] p;
    // p = NULL;

    // for 2D arrayy
    int **ptr = new int *[3];

    for (int i = 0; i < 3; i++)
    {
        ptr[i] = new int[4];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> ptr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}