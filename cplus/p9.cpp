#include <iostream>
using namespace std;

class Sample
{
public:
    int x;
    int y;
    void disp()
    {
        cout << "x=" << x << ",y=" << y << endl;
    }
};

int main()
{
    int Sample::*pc;
    Sample s;
    pc = &Sample::x;
    s.*pc = 10;
    pc = &Sample::y;
    s.*pc = 20;
    s.disp();
}

/*
x=10,y=20

本题说明了类数据成员指针的使用方法。在main()中定义的pc是一个指向Sample类数据成员的指针。
执行pc=&Sample::x时，pc指向数据成员x，语句s.*pc=10等价于s.x=10(为了保证该语句正确执行，Sample类中的x必须是公共成员)；
执行pc=&Sample::y时，pc指向数据成员y，语句s.*pc=20等价于s.y=20(同样，Sample类中的y必须是公共成员)。
所以输出为： x=10,y=20。
*/