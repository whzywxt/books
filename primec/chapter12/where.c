// where.c -- 数据被储存在何处？
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int static_store = 30;
const char *pcg = "String Literal";
int main()
{
    int auto_store = 40;
    char auto_string[] = "Auto char Array";
    int *pi;
    char *pcl;
    pi = (int *)malloc(sizeof(int));
    *pi = 35;
    pcl = (char *)malloc(strlen("Dynamic String") + 1);
    strcpy(pcl, "Dynamic String");

    // 静态数据（包括字符串字面量）占用一个区域
    printf("\n%24s\n", "--Static--");
    printf("static_store: %d at %p\n", static_store, &static_store);
    printf("  %s at %p\n", pcg, pcg);
    printf("   %s at %p\n", "Quoted String", "Quoted String");

    printf("\n%22s\n", "--Auto--");

    printf(" auto_store: %d at %p\n", auto_store, &auto_store);
    printf("%s at %p\n", auto_string, auto_string);

    printf("\n%24s\n", "--Dynamic--");

    printf("       *pi: %d at %p\n", *pi, pi);
    printf("%s at %p\n", pcl, pcl);

    free(pi);
    free(pcl);
    return 0;
}