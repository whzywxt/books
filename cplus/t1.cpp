#include <iostream>

using namespace std;

class Base
{
public:
    virtual void fun()
    {
        cout << 1;
    }
};

class Derived : public Base
{
public:
    void fun()
    {
        cout << 2;
    }
};

int main()
{
    Base *p = new Derived;
    p->fun();
    delete p;
    return 0;
}