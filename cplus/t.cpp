#include <stdio.h>
#include <windows.h>
int main()
{

    int x[6] = {2, 4, 6, 8, 5, 7}, *p = x, i;

    for (i = 0; i < 6; i++)
    {
        printf("%2d", *(p++));
        // printf("%2d", *(p + i));
        // printf("%2d", *p++);
        // printf("%2d", (*p)++);
    }

    // printf("Hello World\n");
    // system("pause");
    return 0;
}