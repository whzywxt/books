#include <stdio.h>
int main(void)
{
    int ref[] = {8, 4, 0, 2};
    int *ptr;
    int index;
    for (index = 0, ptr = ref; index < 4; index++, ptr++)
        printf("%d %d\n", ref[index], *ptr);

    printf("ref = %p, ref + 1 = %p\n", ref, ref + 1);
    --ptr;
    // --ptr;
    // --ptr;
    // --ptr;
    // *ptr++;
    printf("ptr=%p, %d, %d\n", ptr, ptr, *ptr);
    return 0;
}