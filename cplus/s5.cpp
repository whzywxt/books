/*
5．写一个函数，找出给定数组中具有最小值的元素。 
函数的原型： 
 char MinCode(char charAry[]); 
函数参数：charAry所要处理的字符数组名； 
函数返回值：返回具有最小ASCII码的字符。

解：程序可以有多种写法，下面是其中一种 
*/

#include <iostream>
using namespace std;

char MinCode(char charAry[], int len = 10)
{
    char mixCode = 0x0;
    for (int i = 0; i < len; i++)
    {
        if (charAry[i] < mixCode)
            mixCode = charAry[i];
    }
    return mixCode;
}

int main()
{
    int i;
    char site[10] = {'R', 'U', 'N', 'O', 'O', 'B', 'O', 'O', 'B', 'D'};
    i = MinCode(site);

    printf("%d\n", i);
    return 0;
}