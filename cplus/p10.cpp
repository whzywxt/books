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
    Sample s1(2, 3);
    s1.disp();
}

/*
x=2,y=3
*/