#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; /* 假设结点数据是整数 */
#define NoInfo 0         /* 用0表示没有结点 */

// typedef struct TNode *Position;
// typedef Position BinTree; /* 二叉树类型 */
// struct TNode
// {                     /* 树结点定义 */
//     ElementType Data; /* 结点数据 */
//     BinTree Left;     /* 指向左子树 */
//     BinTree Right;    /* 指向右子树 */
// };

/* 队列的定义 */
#include "queue.h"

BinTree CreatBinTree()
{
    ElementType Data;
    BinTree BT, T;
    Queue Queue, *Q; /* 创建空队列 */
    Q = &Queue;
    Q->front = Q->rear = 0;

    /* 建立第1个结点，即根结点 */
    scanf("%d", &Data);
    if (Data != NoInfo)
    {
        /* 分配根结点单元，并将结点地址入队 */
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->Data = Data;
        BT->Left = BT->Right = NULL;
        AddQ(Q, BT);
    }
    else
        return NULL; /* 若第1个数据就是0，返回空树 */

    while (!IsEmpty(Q))
    {
        T = DeleteQ(Q);     /* 从队列中取出一结点地址*/
        scanf("%d", &Data); /* 读入T的左孩子 */
        if (Data == NoInfo)
            T->Left = NULL;
        else
        { /* 分配新结点，作为出队结点左孩子；新结点入队 */
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = Data;
            T->Left->Left = T->Left->Right = NULL;
            AddQ(Q, T->Left);
        }
        scanf("%d", &Data); /* 读入T的右孩子 */
        if (Data == NoInfo)
            T->Right = NULL;
        else
        { /* 分配新结点，作为出队结点右孩子；新结点入队 */
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = Data;
            T->Right->Left = T->Right->Right = NULL;
            AddQ(Q, T->Right);
        }
    } /* 结束while */
    return BT;
}

void PreorderTraversal(BinTree BT)
{
    if (BT)
    {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

int main()
{
    BinTree BT = CreatBinTree();
    PreorderTraversal(BT);
    return 0;
}
