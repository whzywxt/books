#include <iostream>
using namespace std;

class Sample
{
    int x;

public:
    Sample(int a)
    {
        x = a;
        cout << "constructing object:x=" << x << endl;
    }
};

void func(int n)
{
    // 注意：静态对象和静态变量一样，只被构造一次。块作用域的静态变量，在首次进入到定义该静态对象的函数时，构造该静态对象，以后进入该函数时不再构造静态对象。
    static Sample obj(n);
}

int main()
{
    func(1);
    func(10);
}

/*输出
解：counstructing object:x=1
本题说明静态对象构造函数的调用情况，由于在func()函数中定义的对象obj是静态对象，故只被构造一次，所以输出为：
counstructing object:x=1
注意：静态对象和静态变量一样，只被构造一次。块作用域的静态变量，在首次进入到定义该静态对象的函数时，构造该静态对象，以后进入该函数时不再构造静态对象。
*/