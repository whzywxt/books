/* mac_arg.c -- 带参数的宏 */
#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf("The result is %d.\n", X)
int main(void)
{
    int x = 5;
    int z;
    printf("x = %d\n", x);
    z = SQUARE(x);
    printf("Evaluating SQUARE(x): ");
    PR(z);

    z = SQUARE(2);
    printf("Evaluating SQUARE(2): ");
    PR(z);

    printf("Evaluating SQUARE(x+2): ");
    PR(SQUARE(x + 2)); // 宏替换后 x+2*x+2，x=5，求值17

    printf("Evaluating 100/SQUARE(2): ");
    PR(100 / SQUARE(2)); // 宏替换后 100/2*2，求值100

    printf("x is %d.\n", x);
    printf("Evaluating SQUARE(++x): ");
    PR(SQUARE(++x)); // 宏替换后 ++x*++x，递增了两次x，一次在乘法运算之前，一次在乘法运算之后，有些编译器得 6*7=42，有些编译器可能在乘法运算之前已经递增了x，所以7*7=49
    printf("After incrementing, x is %x.\n", x);
    return 0;
}