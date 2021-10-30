#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t start, stop; /* clock_t 是 clock() 函数返回的变量类型 */
double duration;     /* 记录被测函数运行时间, 以秒为单位 */
#define MAXN 10      /* 多项式最大享数，即多项式阶数+1 */
#define MAXK 1e7     /* 被测函数最大重复调用次数 */
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);
void run(double (*f)(int, double *, double), double a[], int case_n);

int main()
{

    int i;
    double a[MAXN]; /* 存储多项式的系数 */

    // 为本题多项式赋值,即a[i]=i
    for (i = 0; i < MAXN; i++)
    {
        a[i] = (double)i;
    }

    printf("CLK_TCK = %d\n", CLK_TCK);
    printf("MAXK = %f\n", MAXK);
    printf("\n");

    run(f1, a, 1);
    run(f2, a, 2);

    // 不在测试范围内的准备工作写在clock()调用之前
    // f1 只执行一次可能测试不出来时间差异 循环调用多次
    // start = clock();
    // for (i = 0; i < MAXK; i++)
    // {
    //     f1(MAXN - 1, a, 1.1);
    // }
    // stop = clock();
    // duration = ((double)(stop - start)) / CLK_TCK / MAXK; // 常数 CLK_TCK 机器时钟每秒所走的时钟打点数
    // printf("ticks1 = %f\n", (double)(stop - start));
    // printf("duration1 = %6.2e\n", duration);

    // f2
    // start = clock();
    // for (i = 0; i < MAXK; i++)
    // {
    //     f2(MAXN - 1, a, 1.1);
    // }
    // stop = clock();
    // duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    // printf("ticks2 = %f\n", (double)(stop - start));
    // printf("duration2 = %6.2e\n", duration);

    return 0;
}

// 求多项式的值方法1
double f1(int n, double a[], double x)
{
    int i;
    double p = a[0];

    for (i = 1; i <= n; i++)
    {
        p += a[i] * pow(x, i);
    }
    return p;
}

// 求多项式的值方法2
double f2(int n, double a[], double x)
{
    int i;
    double p = a[n];

    for (i = n; i > 0; i--)
    {
        p = a[i - 1] + x * p;
    }
    return p;
}

/**
ticks1 = 0.000000
duration1 = 0.00e+000
ticks2 = 0.000000
duration2 = 0.00e+000

// 结果发现 随着重复调用次数增加 f2 的时间 比 f1 小一个数量级
CLK_TCK = 1000
MAXK = 10000000.000000

ticks1 = 1953.000000
duration1 = 1.95e-007
ticks2 = 285.000000
duration2 = 2.85e-008
*/

/* 此函数用于测试被测函数(*f),并且根据case_n输出相应的结果 */
/* case_n 是输出的函数编号: 1 代表 f1 函数, 2 代表 f2 函数 */
void run(double (*f)(int, double *, double), double a[], int case_n)
{
    int i;

    start = clock();
    for (i = 0; i < MAXK; i++)
    {
        (*f)(MAXN - 1, a, 1.1);
    }
    stop = clock();

    duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    printf("ticks%d = %f\n", case_n, (double)(stop - start));
    printf("duration%d = %6.2e\n", case_n, duration);
}
