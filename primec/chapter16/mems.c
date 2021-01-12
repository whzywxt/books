// mems.c -- 使用 memcpy() 和 memmove()
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
void show_array(const int ar[], int n);
void show_array_double(const double ar[], int n);
// 如果编译器不支持C11的_Static_assert，可以注释掉下面这行
_Static_assert(sizeof(double) == 2 * sizeof(int), "double not twice int size");

int main()
{
    int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target[SIZE];
    double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};
    puts("memcpy() used:");
    puts("values (original data): ");
    show_array(values, SIZE);
    memcpy(target, values, SIZE * sizeof(int));
    puts("target (copy of values):");
    show_array(target, SIZE);

    puts("\nUsing memmove() with overlapping ranges:");
    memmove(values + 2, values, 5 * sizeof(int)); // 下标2开始 填充 0 ~ 4 下标元素到 2 ~ 6 位置
    // memmove(values + 2, values, SIZE * sizeof(int));
    puts("values -- elements 0-4 copied to 2-6:");
    show_array(values, SIZE);

    puts("curious (original data): ");
    show_array_double(curious, SIZE / 2);
    puts("\nUsing memcpy() to copy double to int:");
    // memcpy(target, curious, (SIZE / 2) * sizeof(double));
    memmove(target, curious, (SIZE / 2) * sizeof(double));

    puts("target -- 5 doubles into 10 int positions:");
    show_array(target, SIZE);
    // show_array(target, SIZE / 2);
    // show_array(target + 5, SIZE / 2);
    return 0;
}

void show_array(const int ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", ar[i]);
    putchar('\n');
}

void show_array_double(const double ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%f ", ar[i]);
    putchar('\n');
}