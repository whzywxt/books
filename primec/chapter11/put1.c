/* put1.c -- 打印字符串，不添加\n */
#include <stdio.h>
void put1(const char *string) /* 不会改变字符串 */
{
    while (*string != '\0')
        putchar(*string++); // ++优先级高于* 递增的是string本身
}

int main(int argc, char const *argv[])
{
    char *str = "Apple";
    printf("%s\n", str++);
    printf("%s\n", str++);

    // put1("Apple");
    // put1("Ba");
    return 0;
}
