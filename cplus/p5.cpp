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
    Sample s(2, 3), *p = &s;
    p->disp();
}

/*输出
x=2,y=3
*/