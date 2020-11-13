/* arf.c -- 处理数组的函数 */
#include <stdio.h>
#define SIZE 5
void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);

int main(void)
{
    double rates[5] = {88.99, 100.12, 59.45, 183.11, 340.5};
    const double locked[4] = {0.08, 0.075, 0.0725, 0.07};

    double *pnc = rates; // 有效
    // pnc = locked;        // 无效
    pnc = &rates[3]; // 有效

    printf("The pnc array:%p, %d, %d\n", pnc);

    printf("The original dip array:\n");
    show_array(rates, SIZE);
    mult_array(rates, SIZE, 2.5);
    printf("The dip array after calling mult_array():\n");
    show_array(rates, SIZE);
    return 0;
}

/* 显示数组的内容 */
void show_array(const double ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%8.3f ", ar[i]);
    putchar('\n');
}

/* 把数组的每个元素都乘以相同的值 */
void mult_array(double ar[], int n, double mult)
{
    int i;
    for (i = 0; i < n; i++)
        ar[i] *= mult;
}