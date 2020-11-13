// ptr_ops.c -- 指针操作
#include <stdio.h>
int main(void)
{
    int urn[5] = {100, 200, 300, 400, 500};
    int *ptr1, *ptr2, *ptr3;
    ptr1 = urn;     // 把一个地址赋给指针
    ptr2 = &urn[2]; // 把一个地址赋给指针

    printf("ptr1 = %p\n", ptr1);
    printf("ptr2 = %p\n", ptr2);

    printf("ptr2 = ptr1 + 2:\n");
    printf("%p\n", ptr1 + 2);

    printf("ptr2 = urn + 1:\n");
    printf("ptr2 = %p\n", urn + 1);

    return 0;
}