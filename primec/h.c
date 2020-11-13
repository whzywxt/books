#include <stdio.h>
int sum(const int ar[], int n);
#define SIZE 4

int main()
{
    int i;
    int ar[4] = {1, 3, 5, 7};
    printf("Before invoke sum, total: %d\n", sum(ar, SIZE));

    for (i = 0; i < SIZE; i++)
    {
        printf("ar[%d]=%d\n", i, ar[i]);
    }

    printf("After invoke sum, total: %d\n", sum(ar, SIZE));

    return 0;
}

int sum(const int ar[], int n) // 错误的代码
{
    int i;
    int total = 0;
    for (i = 0; i < n; i++)
        total += ar[i]++; // 错误递增了每个元素的值
    return total;
}