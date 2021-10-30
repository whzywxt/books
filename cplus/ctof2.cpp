#include <iostream>
#include <iomanip> //精度控制头文件
using namespace std;
// 摄氏转华氏
int main()
{
    float Fahrenheit; // 华式温度
    float Celsius;    // 摄氏温度

    cin >> Celsius;
    Fahrenheit = 9 * Celsius / 5 + 32; //公式 F＝9×C／5＋32
    cout << "F=" << setiosflags(ios::fixed) << setprecision(2) << Fahrenheit << endl;
    //setiosflags(ios::fixed) 和 serprecision(N) 两个一起用时就表示保留 N 位小数输出
    return 0;
}