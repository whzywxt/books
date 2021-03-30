#include <stdio.h>
int main(void)
{
    int cnt = 0, n = 20, m;
    for (m = 1; m <= n; m = m * 10)
    {
        int a = n / m, b = n % m;
        cnt += (a + 8) / 10 * m + (a % 10 == 1 ? b + 1 : 0);
    }
    printf("cnt=%d", cnt);
    return 0;
}