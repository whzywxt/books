#include <stdio.h>
void show_array(int rows, int cols, int ar[rows][cols]);

int main(void)
{
    /* code */
    // int *ptr;
    // int torf[2][2] = {12, 14, 16};
    // ptr = torf[0];
    // show_array(2, 2, torf);

    // int *ptr;
    // int fort[2][2] = {{12}, {14, 16}};
    // ptr = fort[0];
    // show_array(2, 2, fort);

    // printf("%d, %d", *ptr, *(ptr + 2));

    // int(*ptr)[2];
    // int torf[2][2] = {12, 14, 16};
    // ptr = torf;
    // show_array(2, 2, torf);

    int(*ptr)[2];
    int fort[2][2] = {{12}, {14, 16}};
    ptr = fort;
    show_array(2, 3, fort);

    printf("%d, %d", **ptr, **(ptr + 1));

    return 0;
}

/* 显示数组的内容 */
void show_array(int rows, int cols, int ar[rows][cols])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("[%d][%d]=%d ", i, j, ar[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
