/* 编写一个函数，返回储存在double类型数组中最大值的下标，并在一个简单的程序中测试该函数。*/
#include <stdio.h>
#define LEN 10

int max_arr(const double arr[], int n);
void show_arr(const double arr[], int n);

int main(void)
{
    double orig[LEN] = {19, 2, 3, 4, 215, 6, 7, 8, 159, 10};
    int max;

    show_arr(orig, LEN);
    max = max_arr(orig, LEN);
    printf("%d = largest value index\n", max);

    return 0;
}

int max_arr(const double arr[], int n)
{
    int i;
    /* don't use 0 as initial max value -- fails if all array values are neg */
    int max = arr[0];
    int index = 0;
    for (i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

void show_arr(const double arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%f ", arr[i]);
    }
    putchar('\n');
}
