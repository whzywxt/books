#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1;

typedef int ElementType;
typedef int Position;

typedef struct QNode *PtrToQNode;

struct QNode
{
    ElementType *Data;    // 存储元素的数组
    Position Front, Rear; // 队列的头尾指针
    int MaxSize;          // 队列最大容量
};
typedef PtrToQNode Queue;

#include "45110-A0/3-17.c"
/*****以上不出现在教材正文里*******/

int main()
{
    Queue Q = CreateQueue(5);

    AddQ(Q, 1);
    AddQ(Q, 2);
    DeleteQ(Q);
    DeleteQ(Q);
    DeleteQ(Q);
    AddQ(Q, 3);
    AddQ(Q, 4);
    AddQ(Q, 5);
    AddQ(Q, 5);
    AddQ(Q, 5);
    
    return 0;
}
