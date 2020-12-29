//* book.c -- 一本书的图书目录 */
#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);
#define MAXTITL 41 /* 书名的最大长度 + 1  */
#define MAXAUTL 31 /* 作者姓名的最大长度 + 1*/
struct book
{ /* 结构模版：标记是 book */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
}; /* 结构模版结束    */

int main(void)
{
    struct book gift = {
        .value = 25.99,
        .author = "James Broadfool",
        .title = "Rue for the Road"};
    printf("%s by %s: $%.2f\n", gift.title, gift.author, gift.value);
    printf("%s: \"%s\" ($%.2f)\n", gift.author, gift.title, gift.value);

    struct book surprise = {
        .value = 18.90,
        .author = "James Broadfool",
        0.25};
    printf("%s by %s: $%.2f\n", surprise.title, surprise.author, surprise.value);
    printf("%s: \"%s\" ($%.2f)\n", surprise.author, surprise.title, surprise.value);
    printf("Done.\n");
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // 查找换行符
        if (find)                // 如果地址不是 NULL,
            *find = '\0';        // 在此处放置一个空字符
        else
            while (getchar() != '\n')
                continue; //处理输入行中剩余的字符
    }
    return ret_val;
}