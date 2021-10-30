#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t start, stop; /* clock_t 是 clock() 函数返回的变量类型 */
double duration;     /* 记录被测函数运行时间, 以秒为单位 */
#define MAXN 100      /* 多项式最大享数，即多项式阶数+1 */
#define MAXK 1e5     /* 被测函数最大重复调用次数 */

int MaxSubseqSum1(int List[], int N)
{
    int i, j, k;
    int ThisSum, MaxSum = 0;

    for (i = 0; i < N; i++)
    {
        // i 是子列左端位置，j是子列右端位置
        for (j = i; j < N; j++)
        {
            ThisSum = 0; // List[i] 到 List[j] 的子列和

            for (k = i; k <= j; k++)
            {
                ThisSum += List[k];
            }

            if (ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
            // printf("i: %d, j: %d, k: %d, ThisSum: %d, MaxSum: %d\n", i, j, k, ThisSum, MaxSum);
        } // j 循环结束

        // printf("\n");

    } // i 循环结束

    return MaxSum;
}

int MaxSubseqSum2(int List[], int N)
{
    int i, j;
    int ThisSum, MaxSum = 0;

    for (i = 0; i < N; i++)
    {
        ThisSum = 0;
        // i 是子列左端位置，j是子列右端位置
        for (j = i; j < N; j++)
        {
            ThisSum += List[j];

            if (ThisSum > MaxSum)
            {
                MaxSum = ThisSum;
            }
            // printf("i: %d, j: %d, ThisSum: %d, MaxSum: %d\n", i, j, ThisSum, MaxSum);
        } // j 循环结束

        // printf("\n");

    } // i 循环结束

    return MaxSum;
}

/* 此函数用于测试被测函数(*f),并且根据case_n输出相应的结果 */
/* case_n 是输出的函数编号: 1 代表 f1 函数, 2 代表 f2 函数 */
void run(int (*f)(int[], int), int a[], int case_n)
{
    int i;

    start = clock();
    for (i = 0; i < MAXK; i++)
    {
        (*f)(a, MAXN);
    }
    stop = clock();

    // duration = ((double)(stop - start)) / CLK_TCK / MAXK;
    duration = ((double)(stop - start)) / CLK_TCK;
    printf("ticks%d = %f\n", case_n, (double)(stop - start));
    printf("duration_%d = %6.2e\n", case_n, duration);
    printf("duration__%d = %f\n", case_n, duration);
}

// 返回3个整数中的最大值
int Max3(int A, int B, int C)
{
    return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer(int List[], int left, int right)
{
    // 分治法求 List[left] 到 List[right]的最大子列和
    int MaxLeftSum, MaxRightSum;             // 存放左右子问题的解
    int MaxLeftBorderSum, MaxRightBorderSum; // 存放跨分界线的结果

    int LeftBorderSum, RightBorderSum;
    int center, i;

    // 递归终止条件，子列只有1个数字
    if (left == right)
    {
        if (List[left] > 0)
        {
            return List[left];
        }
        else
        {
            return 0;
        }
    }

    // 下面是 “分” 的过程
    center = (left + right) / 2;

    // 递归求得两边子列的最大和
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    // 下面求跨分界线的最大子列和
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;

    // 从中线向左扫描
    for (i = center; i >= left; i--)
    {
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)
        {
            MaxLeftBorderSum = LeftBorderSum;
        }
    } // 左边扫描end

    MaxRightBorderSum = 0;
    RightBorderSum = 0;

    // 从中线向右扫描
    for (i = center + 1; i <= right; i++)
    {
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
        {
            MaxRightBorderSum = RightBorderSum;
        }
    } // 右边扫描end

    // 返回 “治” 的结果
    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubseqSum3(int List[], int N)
{
    return DivideAndConquer(List, 0, N - 1);
}

int MaxSubseqSum4(int List[], int N)
{
    int i;
    int ThisSum, MaxSum;

    ThisSum = MaxSum = 0;
    for (i = 0; i < N; i++)
    {
        ThisSum += List[i]; // 向右累加

        if (ThisSum > MaxSum)
        {
            MaxSum = ThisSum; // 发现更大和则更新当前结果
        }
        else if (ThisSum < 0)
        {
            ThisSum = 0; // 如果当前子列和为负， 则不可能使后面的部分和增大， 抛弃
        }

    } // i 循环结束

    return MaxSum;
}

int main()
{
    // int a[6] = {-2, 11, -4, 13, -5, -2};
    // int a[8] = {-1, 3, -2, 4, -6, 1, 6, -1};
    int a[MAXN];

    int i, n;
    time_t t;

    /* 初始化随机数发生器 */
    srand((unsigned)time(&t));

    /* 输出 0 到 49 之间的 5 个随机数 */
    for (i = 0; i < MAXN; i++)
    {
        a[i] = rand() % 2001 - 1000;
        // printf("a[%d] = %d\n", i, a[i]);
    }

    run(MaxSubseqSum1, a, 1);
    run(MaxSubseqSum2, a, 2);
    run(MaxSubseqSum3, a, 3);
    run(MaxSubseqSum4, a, 4);

    printf("func1: %d\n", MaxSubseqSum1(a, MAXN));
    printf("func2: %d\n", MaxSubseqSum2(a, MAXN));
    printf("func3: %d\n", MaxSubseqSum3(a, MAXN));
    printf("func4: %d\n", MaxSubseqSum4(a, MAXN));

    return 0;
}