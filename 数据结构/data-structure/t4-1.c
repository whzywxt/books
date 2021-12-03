#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NoInfo 0 /* 用0表示没有结点 */
#define ERROR NULL;

// typedef struct TNode *BinTree;
// struct TNode
// {
//     int Data;
//     struct TNode *Left;
//     struct TNode *Right;
// };

typedef int TreeDataType;

typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode
{                      /* 树结点定义 */
    TreeDataType Data; /* 结点数据 */
    BinTree Left;      /* 指向左子树 */
    BinTree Right;     /* 指向右子树 */
};

typedef BinTree ElementType; /* 假设结点数据是整数 */

/* 队列定义 */
typedef struct QNode *PtrToQNode;
struct QNode
{
    ElementType *Data; // 存储元素的数组
    int Front, Rear;   // 队列的头尾指针
    int MaxSize;       // 队列最大容量
};
typedef PtrToQNode Queue;

/* 队列的定义 */
// #include "queue.h"
#include "Queue.c"

BinTree CreatBinTree()
{
    TreeDataType Data;
    BinTree BT, T;
    // Queue Queue, Q; /* 创建空队列 */
    // Q = &Queue;
    // Q->front = Q->rear = 0;

    Queue Q = CreateQueue(100);

    /* 建立第1个结点，即根结点 */
    scanf("%d", &Data);
    printf("第一个结点: %d\n", Data);
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
        T = DeleteQ(Q); /* 从队列中取出一结点地址*/
        printf("结点: %d\n", T->Data);
        scanf("%d", &Data); /* 读入T的左孩子 */
        printf(" |-左孩子: %d\n", Data);
        if (Data == NoInfo)
        {
            T->Left = NULL;
        }
        else
        { /* 分配新结点，作为出队结点左孩子；新结点入队 */
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = Data;
            T->Left->Left = T->Left->Right = NULL;
            AddQ(Q, T->Left);
        }
        scanf("%d", &Data); /* 读入T的右孩子 */
        printf(" |-右孩子: %d\n", Data);
        if (Data == NoInfo)
        {
            T->Right = NULL;
        }
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

#include "TreeTraversal.c"

int main()
{
    // 运行后 输入 1 2 3 4 5 6 7 0 8 0 0 9 10 0 0 0 0 0 0 0 0
    BinTree BT = CreatBinTree();

    printf("先序遍历\n");
    PreorderTraversal(BT);
    printf("\n");

    printf("中序遍历\n");
    InorderTraversal(BT);
    printf("\n");

    printf("后序遍历\n");
    PostorderTraversal(BT);
    printf("\n");

    return 0;
}
