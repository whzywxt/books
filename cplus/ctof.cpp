#include <iostream>
using namespace std;
int main()
{
    double HS, SS;
    int a;
    cout << "Please selct:1 Fahrenheit convert Celsius, 2 ­celsius convert Fahrenheit" << endl;
    while (cin >> a)
    {
        if (a == 1)
        {
            cout << "Please input Fahrenheit:" << endl;
            cin >> HS;
            SS = (5 / 9.0) * (HS - 32);
            cout << "­celsius result:" << SS << endl;
            break;
        }
        else if (a == 2)
        {
            cout << "Please input Celsius:" << endl;
            cin >> SS;
            HS = (9 / 5.00) * SS + 32;
            cout << "Fahrenheit result:" << HS << endl;
            break;
        }
        else
        {
            cout << "Input data error, please input 1 or 2" << endl;
        }
    }
}