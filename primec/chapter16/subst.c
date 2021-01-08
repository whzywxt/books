/* subst.c -- 在字符串中替换 */
#include <stdio.h>
#define PSQR(x) printf("The square of " #x " is %d.\n", ((x) * (x)))
int main(void)
{
    int y = 5;
    PSQR(y); // 用 "y" 替换 #x
    PSQR(2 + 4); // 用 "2 + 4" 替换 #x
    return 0;
}