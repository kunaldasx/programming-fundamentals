// Inheritance
#include <iostream>
using namespace std;

// Single Inheritance
// class A
// {
// public:
//     void func()
//     {
//         cout << "A Called" << endl;
//     }
// };

// class B : public A
// {
// };

// int main()
// {
//     B b;
//     b.func();
//     return 0;
// }

// Multiple Inheritance
// class A
// {
// public:
//     void funcA()
//     {
//         cout << "A Called" << endl;
//     }
// };

// class B
// {
// public:
//     void funcB()
//     {
//         cout << "B Called" << endl;
//     }
// };

// class C : public A, public B
// {
// public:
//     void funcC()
//     {
//         cout << "C Called" << endl;
//     }
// };

// int main()
// {
//     C c;
//     c.funcA();
//     c.funcB();
//     c.funcC();
//     return 0;
// }

// Multilevel Inheritance
// class A
// {
// public:
//     A()
//     {
//         cout << "A Constructor" << endl;
//     }

//     void funcA()
//     {
//         cout << "A Called" << endl;
//     }
// };

// class B : public A
// {
// public:
//     B()
//     {
//         cout << "B Constructor" << endl;
//     }

//     void funcB()
//     {
//         cout << "B Called" << endl;
//     }
// };

// class C : public B
// {
// public:
//     C()
//     {
//         cout << "C Constructor" << endl;
//     }

//     void funcC()
//     {
//         cout << "C Called" << endl;
//     }
// };

// int main()
// {
//     C c; // Constructor Chaining
//     c.funcA();
//     c.funcB();
//     c.funcC();
//     return 0;
// }

// Hierarchical Ingeritance
class A
{
public:
    A()
    {
        cout << "A Constructor" << endl;
    }

    void funcA()
    {
        cout << "A Called" << endl;
    }
};

class B : public A
{
public:
    B()
    {
        cout << "B Constructor" << endl;
    }

    void funcB()
    {
        cout << "B Called" << endl;
    }
};

class C : public A
{
public:
    C()
    {
        cout << "C Constructor" << endl;
    }

    void funcC()
    {
        cout << "C Called" << endl;
    }
};

int main()
{
    B b;
    b.funcA();
    b.funcB();
    C c; // Constructor Chaining
    c.funcA();
    c.funcC();
    return 0;
}