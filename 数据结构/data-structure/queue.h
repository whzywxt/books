#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MaxSize 100

typedef struct TNode *BinTree;
struct TNode
{
    int Data;
    struct TNode *Left;
    struct TNode *Right;
};

typedef struct
{
    BinTree Data[MaxSize];
    int front;
    int rear;
} Queue;

int IsEmpty(Queue *Q)
{
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

void AddQ(Queue *Q, BinTree item)
{
    if ((Q->rear + 1) % MaxSize == Q->front)
    {
        printf("队已满\n");
        return;
    }
    else
    {
        Q->rear = (Q->rear + 1) % MaxSize;
        Q->Data[Q->rear] = item;
    }
}

BinTree DeleteQ(Queue *Q)
{
    if (Q->rear == Q->front)
    {
        printf("队已空\n");
        return NULL;
    }
    else
    {
        Q->front = (Q->front + 1) % MaxSize;
        return Q->Data[Q->front];
    }
}

#endif // QUEUE_H_INCLUDED