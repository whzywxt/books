#include <iostream>
using namespace std;

/*
华氏温度转换为摄氏温度的公式为：C=(F-32)/1.8。
*/

class convert
{
public:
    convert(double i) { val1 = i; }
    virtual void compute() = 0;

protected:
    double val1;
    double val2;
};

// liters to gallons
class l_to_g : public convert
{
public:
    l_to_g(double i) : convert(i) {}
    void compute()
    {
        // 1加仑有多少公升？答案是3.7854118。
        val2 = val1 / 3.7854;
        cout << val1 << " liters is " << val2 << " gallons." << endl;
    }
};

// Fahrenheit to Celsius
class f_to_c : public convert
{
public:
    f_to_c(double i) : convert(i) {}
    void compute()
    {
        val2 = (val1 - 32) * 5 / 9;
        cout << val1 << " Fahrenheit is " << val2 << " Celsius." << endl;
    }
};

// Celsius to Fahrenheit
class c_to_f : public convert
{
public:
    c_to_f(double i) : convert(i) {}
    void compute()
    {
        // val2 = (val1 - 32) * 5 / 9;
        val2 = val1 * 9 / 5 + 32;
        cout << val1 << " Celsius is " << val2 << " Fahrenheit." << endl;
    }
};

void fun(convert &f)
{
    f.compute();
}

int main()
{
    l_to_g lgobj(4);
    l_to_g lgobj1(20);
    l_to_g lgobj2(50);

    f_to_c fcobj(100);
    f_to_c fcobj1(70);
    f_to_c fcobj2(-40);

    c_to_f cfobj(37.7778);
    c_to_f cfobj1(21.1111);
    c_to_f cfobj2(-40);

    fun(lgobj);
    fun(lgobj1);
    fun(lgobj2);

    fun(fcobj);
    fun(fcobj1);
    fun(fcobj2);

    fun(cfobj);
    fun(cfobj1);
    fun(cfobj2);
}
