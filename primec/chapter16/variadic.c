// variadic.c -- 变参宏
#include <stdio.h>
#include <math.h>
#define PR(X, ...) printf("Message " #X ": " __VA_ARGS__)
int main(void)
{
    double x = 48;
    double y;
    y = sqrt(x);
    PR(1, "x = %g\n", x); // 调用，X的值是1，所以#X变成"1"。展开后成为：printf("Message " "1" ": " "x = %g\n", x); 串联4个字符，简化为 printf("Message 1: x = %g\n", x);
    PR(2, "x = %.2f, y = %.4f\n", x, y);
    return 0;
}