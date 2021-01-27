/* 
编写并测试一个函数larger_of()，该函数把两个double类型变量的值替
换为较大的值。例如， larger_of(x, y)会把x和y中较大的值重新赋给两个变
量。 
*/
#include <stdio.h>

void larger_of(double *p1, double *p2);

int main(void)
{
    double x, y;

    printf("Enter tow numbers (q to quit): \n");
    while (scanf("%lf %lf", &x, &y) == 2)
    {
        larger_of(&x, &y);
        printf("The modified values are %f and %f.\n", x, y);
        printf("Next two values (q to quit): \n");
    }
    printf("Bye!\n");

    return 0;
}

void larger_of(double *p1, double *p2)
{
    if (*p1 > *p2)
    {
        *p2 = *p1;
    }
    else
    {
        *p1 = *p2;
    }
}
