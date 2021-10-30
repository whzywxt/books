#include <iostream>
using namespace std;
class A
{
public:
    A() { cout << "A"  << endl; }
};
class B
{
public:
    B() { cout << "B"  << endl; }
};
class C : public A
{
public:
    C() { cout << "C " << endl; }

private:
    B b;
};
int main()
{
    C obj;
    return 0;
}