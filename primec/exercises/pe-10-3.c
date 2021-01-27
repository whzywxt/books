/* 编写一个函数，返回储存在int类型数组中的最大值，并在一个简单的程序中测试该函数。*/
#include <stdio.h>
#define LEN 10

int max_arr(const int arr[], int n);
void show_arr(const int arr[], int n);

int main(void)
{
    int orig[LEN] = {19, 2, 3, 4, 15, 6, 7, 8, 19, 10};
    int max;

    show_arr(orig, LEN);
    max = max_arr(orig, LEN);
    printf("%d = largest value\n", max);

    return 0;
}

int max_arr(const int arr[], int n)
{
    int i;
    /* don't use 0 as initial max value -- fails if all array values are neg */
    int max = arr[0];
    for (i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void show_arr(const int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
}
