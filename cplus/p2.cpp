#include <iostream>

using namespace std;

class A
{
public:
    A() { cout << "A's con." << endl; }
    ~A() { cout << "A's des." << endl; }
};
class B
{
public:
    B() { cout << "B's con." << endl; }
    ~B() { cout << "B's des." << endl; }
};
class C : public A, public B
{
public:
    C() : member(), B(), A() { cout << "C's con." << endl; }
    ~C() { cout << "C's des." << endl; }

private:
    A member;
};
int main()
{
    C obj;
}

/*
A's con.
B's con.
A's con.
C's con.
C's des.
A's des.
B's des.
A's des.
*/

/*
答：A's con.
B's con.
A's con.
C's con.
C's des.
A's des.
B's des.
A's des.
*/