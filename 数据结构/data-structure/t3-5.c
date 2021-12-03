#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR -1;

typedef int ElementType;
typedef int Position;

typedef struct QNode *PtrToQNode;

struct QNode
{
    ElementType *Data;    // �洢Ԫ�ص�����
    Position Front, Rear; // ���е�ͷβָ��
    int MaxSize;          // �����������
};
typedef PtrToQNode Queue;

#include "45110-A0/3-17.c"
/*****���ϲ������ڽ̲�������*******/

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
