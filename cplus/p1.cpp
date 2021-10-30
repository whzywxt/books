#include <iostream>

using namespace std;

class Test;
void fun1(Test t);
Test fun2();
class Test
{
public:
    Test(int n = 1)
    {
        val = n;
        cout << "Con." << endl;
    }
    Test(const Test &t)
    {
        val = t.val;
        cout << "Copy con." << endl;
    }
    Test &operator=(Test &t)
    {
        val = t.val;
        cout << "Assignment." << endl;
        return *this;
    }

private:
    int val;
};
int main()
{
    Test t1(1);
    Test t2 = t1;
    Test t3;
    t3 = t1;
    fun1(t2);
    // t3 = fun2(); // t2.cpp:21:11: note:   no known conversion for argument 1 from 'Test' to 'Test&'
}
void fun1(Test t) {}
Test fun2()
{
    Test t;
    return t;
}

/*
注释掉 t3=fun2() 输出内容
Con.
Copy con.
Con.
Assignment.
Copy con.
*/

/**
答：Con.
Copy con.
Con.
Assignment.
Copy con.
Con.
Copy con.
Assignment.
*/