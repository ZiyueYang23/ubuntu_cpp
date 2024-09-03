// @ 好题一
// #include <iostream>
// using namespace std;

// class Base
// {
// public:
//     Base(int i) : b(i)
//     {
//         cout << b << endl;
//     }
//     ~Base()
//     {
//         cout << "~" << b << endl;
//     }

// private:
//     int b;
// };
// class Derived : public Base
// {
// public:
//     Derived(int i) : Base(3), d(i), m_objA(1)
//     {
//         cout << d << endl;
//     }
//     ~Derived()
//     {
//         cout << "~" << d << endl;
//     }

// private:
//     int d;
//     Base m_objA;
// };

// int main()
// {
//     Derived d1(4);
// }

// @ 好题二
// #include <iostream>
// using namespace std;

// class Shape
// {
// public:
//     virtual void Print()
//     {
//         cout << "A Shape" << endl;
//     }
// };

// class Circle :public Shape
// {
// public:
//     virtual void Print()
//     {
//         cout << "A Circle" << endl;
//     }
// };

// int main()
// {
//     Shape s1;
//     Circle s2;
//     s2.Shape::Print();

//     Shape &rs1 = s1;
//     rs1.Print();
//     Shape &rs2 = s2;
//     rs2.Print();

//     Shape ss1 = rs1;
//     ss1.Print();
//     Shape ss2 = rs2;
//     ss2.Print();
//     return 0;
// }
// @ 好题三
// #include <iostream>

// #include <string>

// using namespace std;

// class A
// {

// public:
//     virtual void f() { cout << "A"; }

//     void g() { cout << "B"; }

//     void h() { cout << "E"; }
// };

// class B : public A
// {

// public:
//     virtual void f() { cout << "C"; }

//     void g() { cout << "D"; }

//     virtual void h() { cout << "F"; }
// };

// void show(A &a)
// {
//     a.f();
//     a.g();
//     a.h();
// }

// int main()
// {

//     B b;

//     show(b);
// }
// @ 好题四
#include <iostream>
using namespace std;

class Stool
{
public:
    Stool()
    {
        cout << "A" << endl;
    }
};
class Chair : public Stool
{
public:
    Chair()
    {
        cout << "B" << endl;
    }
};

class ArmChair : public Chair
{
public:
    ArmChair()
    {
        cout << "C" << endl;
    }
};

int main()
{
    Chair chair;
    ArmChair armChair;
}
