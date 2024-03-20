// Function Overloading (compile Time Polymorphism)
#include <iostream>
using namespace std;

class A
{
public:
    float area(int radius)
    {
        return 3.14 * radius * radius;
    } // area of circle

    int area(int l, int b)
    {
        return l * b;
    } // area of rectangle

    void area()
    {
        cout << "Area Called" << endl;
    }
    // Function Overloading cannot be achieved by just changing the return type of the function.
    // There must be a difference in their arguments
};
int main()
{
    A a;
    cout << a.area(7) << endl;
    cout << a.area(4, 5) << endl;
    a.area();
    return 0;
}