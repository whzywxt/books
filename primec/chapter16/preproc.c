/* preproc.c -- 简单的预处理示例 */
#include <stdio.h>
#define TWO 2 /* 可以使用注释 */
#define OW "Consistency is the last refuge of the unimagina\
tive.- Oscar Wilde" /* 反斜杠把该定义延续到下一行 */
#define FOUR TWO *TWO
#define PX printf("X is %d.\n", x)
#define FMT "X is %d.\n"

#define HAL 'Z'
#define HAP "Z"

#define SIX 2 * 3
#define SIX 2 * 3
// #define SIX 3 * 3 // 编译会有警告
// #define SIX 2*3 // 编译会有警告
// #define TWO 20 // 编译会有警告

int main(void)
{
    int x = TWO;
    PX;
    x = FOUR; // x = TWO*TWO，宏展开，只替换，不求值
    printf(FMT, x);
    printf("%s\n", OW);
    printf("TWO: OW\n");

    printf("%c\n", HAL);
    printf("%s\n", HAP);

    printf("SIX: %d\n", SIX);
    printf("%d", SIX);
    return 0;
}