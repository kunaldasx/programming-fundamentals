// Operator Overloading (Compile time polymorphism)
#include <iostream>
using namespace std;

// Syntax for Operator Overloading
/* return_type operator+(){
        return a+b;   Here a is the current object's prop and b is the input
} */

class Complex
{
private:
    int real;
    int img;

public:
    Complex(int r, int i)
    {
        real = r;
        img = i;
    }

    Complex()
    {
    }

    // Operator Overloading
    Complex operator+(Complex const &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.img = img + obj.img;
        return res;
    }

    void display()
    {
        cout << real << " + i" << img << endl;
    }
};

int main()
{
    Complex obj1(12, 7), obj2(5, 7);
    Complex obj3 = obj1 + obj2;
    obj3.display();
    return 0;
}