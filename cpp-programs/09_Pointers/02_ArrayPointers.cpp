// Array Pointers
#include <iostream>
using namespace std;

int main()
{
    int ar[] = {10, 20, 30};

    cout << *ar << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << *(ar + i) << " ";
    }
    cout << endl;

    int *ptr = ar;
    for (int i = 0; i < 3; i++)
    {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;
    return 0;
}