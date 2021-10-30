/*
3．写一个函数，用递归函数完成以下运算:
sum(n) =  1 – 1/2 + 1/3 – 1/4 + … -(1/n)*(-1)n        （其中n>0） 
函数原型：	float sum(int n); 
函数参数：n为正整数。 
函数返回值：相应于给定的n，右边表达式运算结果。
提示：你可以使用递归表达式：	sum(n) = sum(n-1) -(1/n)*(-1)n
*/

#include <iostream>
#include <math.h>
using namespace std;

float sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        if (n % 2 == 0)
        {
            return sum(n - 1) - (1.0 / n);
        }
        else
        {
            return sum(n - 1) + (1.0 / n);
        }
    }
}

int main()
{
    float i;
    i = sum(4);

    printf("%f\n", i);
    return 0;
}