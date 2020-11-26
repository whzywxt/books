/* nono.c -- 千万不要模仿！ */
#include <stdio.h>
int main(void)
{
    char side_a[] = "Side A";
    char dont[] = {'W', 'O', 'W', '!'};
    char side_b[] = "Side B";
    // 通常内存中有许多空字符，如果幸运的话，puts()很快就会发现一个。但是，这样做很不靠谱。
    puts(dont); /* dont 不是一个字符串 */
    return 0;
}