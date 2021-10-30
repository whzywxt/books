#include <iostream>
using namespace std;

class Sample
{
    int x, y;

public:
    // 默认构造函数
    Sample() { x = y = 0; }

    // 重载构造函数
    Sample(int a, int b)
    {
        x = a;
        y = b;
    }

    // 析构函数 注意：析构函数在对象的作用域结束时被自动隐式调用。
    ~Sample()
    {
        if (x == y)
            cout << "x=y" << endl;
        else
            cout << "x!=y" << endl;
    }

    void disp()
    {
        cout << "x=" << x << ",y=" << y << endl;
    }
};

int main()
{
    Sample s1(2, 3);
    s1.disp();
}

/*输出
x=2,y=3
x!=y
*/