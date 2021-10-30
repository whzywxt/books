#include <iostream>
using namespace std;

class Sample
{
    int x, y;

public:
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
    Sample s1, s2(2, 3);
    s1.disp(); // x=0,y=0 s1 调用其默认构造函数
    s2.disp(); // x=2,y=3 s2 调用其重载构造函数, 再调用成员函数
}

/*输出
x=0,y=0
x=2,y=3
*/