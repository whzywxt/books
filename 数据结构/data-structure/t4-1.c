#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NoInfo 0 /* ��0��ʾû�н�� */
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
typedef Position BinTree; /* ���������� */
struct TNode
{                      /* ����㶨�� */
    TreeDataType Data; /* ������� */
    BinTree Left;      /* ָ�������� */
    BinTree Right;     /* ָ�������� */
};

typedef BinTree ElementType; /* ���������������� */

/* ���ж��� */
typedef struct QNode *PtrToQNode;
struct QNode
{
    ElementType *Data; // �洢Ԫ�ص�����
    int Front, Rear;   // ���е�ͷβָ��
    int MaxSize;       // �����������
};
typedef PtrToQNode Queue;

/* ���еĶ��� */
// #include "queue.h"
#include "Queue.c"

BinTree CreatBinTree()
{
    TreeDataType Data;
    BinTree BT, T;
    // Queue Queue, Q; /* �����ն��� */
    // Q = &Queue;
    // Q->front = Q->rear = 0;

    Queue Q = CreateQueue(100);

    /* ������1����㣬������� */
    scanf("%d", &Data);
    printf("��һ�����: %d\n", Data);
    if (Data != NoInfo)
    {
        /* �������㵥Ԫ����������ַ��� */
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->Data = Data;
        BT->Left = BT->Right = NULL;
        AddQ(Q, BT);
    }
    else
        return NULL; /* ����1�����ݾ���0�����ؿ��� */

    while (!IsEmpty(Q))
    {
        T = DeleteQ(Q); /* �Ӷ�����ȡ��һ����ַ*/
        printf("���: %d\n", T->Data);
        scanf("%d", &Data); /* ����T������ */
        printf(" |-����: %d\n", Data);
        if (Data == NoInfo)
        {
            T->Left = NULL;
        }
        else
        { /* �����½�㣬��Ϊ���ӽ�����ӣ��½����� */
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = Data;
            T->Left->Left = T->Left->Right = NULL;
            AddQ(Q, T->Left);
        }
        scanf("%d", &Data); /* ����T���Һ��� */
        printf(" |-�Һ���: %d\n", Data);
        if (Data == NoInfo)
        {
            T->Right = NULL;
        }
        else
        { /* �����½�㣬��Ϊ���ӽ���Һ��ӣ��½����� */
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = Data;
            T->Right->Left = T->Right->Right = NULL;
            AddQ(Q, T->Right);
        }
    } /* ����while */

    return BT;
}

#include "TreeTraversal.c"

int main()
{
    // ���к� ���� 1 2 3 4 5 6 7 0 8 0 0 9 10 0 0 0 0 0 0 0 0
    BinTree BT = CreatBinTree();

    printf("�������\n");
    PreorderTraversal(BT);
    printf("\n");

    printf("�������\n");
    InorderTraversal(BT);
    printf("\n");

    printf("�������\n");
    PostorderTraversal(BT);
    printf("\n");

    return 0;
}
