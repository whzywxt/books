#include <iostream>
using namespace std;

class Sample
{
public:
    int x, y;
    Sample() { x = y = 0; }
    Sample(int a, int b)
    {
        x = a;
        y = b;
    }
    void disp()
    {
        cout << "x=" << x << ",y=" << y << endl;
    }
};

int main()
{
    // 注意：构造函数是唯一不能被显式调用的成员函数，它在定义类的对象时自动调用，也称为隐式调用。
    Sample s1(2, 3); // 调用其重载构造函数
    s1.disp(); // 调用成员函数
}

/*输出
x=2,y=3
*/