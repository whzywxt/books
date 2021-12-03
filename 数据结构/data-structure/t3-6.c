#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 迷宫数据结构 */
#define MAXMATRIXSIZE 100 /* 迷宫矩阵最大行列数 */
#define MAXSTACKSIZE 2000 /* 堆栈最大规模 */

struct Offsets
{                    /* 偏移量结构定义 */
    short int Vert;  /* 纵向偏移 */
    short int Horiz; /* 横向偏移 */
};

struct MazePosition
{                  /* 迷宫中的位置结构 */
    short int Row; /* 行号 */
    short int Col; /* 列号 */
    short int Dir; /* 对应偏移量数组的方向号 */
};
typedef struct MazePosition ElementType; /* 堆栈元素类型 */

typedef int Position;
struct SNode
{
    ElementType *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode *Stack;

ElementType ERROR = {0, 0, 0};

/* 堆栈的创建及入栈和出栈的函数 */
#include "45110-A0/3-11.c"
#include "45110-A0/3-12.c"
#include "45110-A0/3-13.c"

#include "45110-A0/3-20.c"

int main()
{

    // 四周都是1 表示迷宫墙壁路不通
    int Maze[][MAXMATRIXSIZE] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1},
        {1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    Path(Maze, 15, 11);

    return 0;
}
