#include <iostream>
#include <iomanip> // 精度控制头文件
using namespace std;
// 华氏转摄氏
int main()
{
    float Fahrenheit; // 华式温度
    float Celsius; // 摄氏温度
    cin >> Fahrenheit;
    
    Celsius = 5 * (Fahrenheit - 32) / 9; // 公式 C=5(F-32)/9
    cout << "C=" << setiosflags(ios::fixed) << setprecision(2) << Celsius << endl;
    //setiosflags(ios::fixed) 和 serprecision(N) 两个一起用时就表示保留 N 位小数输出
    return 0;
}