// Cpp program to show the
// implementation of Jagged Arrays

#include <iostream>
using namespace std;

int main()
{

    int row0[4] = {1, 2, 3, 4};
    int row1[2] = {5, 6};
    int row3[3] = {7, 8, 9};

    int *jagged[3] = {row0, row1, row3};

    // Array to hold the size of each row
    int Size[3] = {4, 2, 3};

    // To display elements of Jagged array
    for (int i = 0; i < 3; i++)
    {
        // pointer to hold the address of the row
        int *ptr = jagged[i];

        for (int j = 0; j < Size[i]; j++)
        {
            cout << *ptr << " ";

            // move the pointer to the
            // next element in the row
            ptr++;
        }
        cout << endl;
    }
    return 0;
}
