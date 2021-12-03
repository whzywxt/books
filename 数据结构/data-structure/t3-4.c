#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode
{
    ElementType *Data; /* 存储元素的数组 */
    Position Top1;     /* 堆栈 1 的栈顶指针 */
    Position Top2;     /* 堆栈 2 的栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef PtrToSNode Stack;

#define ERROR -1;

// 顺序栈的创建
Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top1 = -1;
    S->Top2 = MaxSize;
    S->MaxSize = MaxSize;

    return S;
}

bool IsFull(Stack S)
{
    return (S->Top2 - S->Top1 == 1);
}

// Tag 作为区分两个堆栈的标志, 取值为 1 和 2
bool Push(Stack S, ElementType X, int Tag)
{
    if (IsFull(S))
    {
        printf("堆栈 %d 满\n", Tag);
        return false;
    }
    else
    {
        if (Tag == 1)
        {
            S->Data[++(S->Top1)] = X;
        }
        else
        {
            S->Data[--(S->Top2)] = X;
        }

        return true;
    }
}

bool IsEmpty(Stack S, int Tag)
{
    if (Tag == 1)
    {
        // 堆栈 1 空
        return (S->Top1 == -1);
    }
    else
    {
        // 堆栈 2 空
        return (S->Top2 == S->MaxSize);
    }
}

ElementType Pop(Stack S, int Tag)
{
    if (IsEmpty(S, Tag))
    {
        printf("堆栈 %d 空\n", Tag);
        return ERROR;
    }
    else
    {
        if (Tag == 1)
        {
            return (S->Data[(S->Top1)--]);
        }
        else
        {
            return (S->Data[(S->Top2)++]);
        }
    }
}

int main()
{
    Stack S = CreateStack(5);
    ElementType i;

    Push(S, 1, 1);
    Push(S, 10, 1);
    Push(S, 100, 1);

    Push(S, 1000, 2);
    Push(S, 10000, 2);
    Push(S, 100000, 2);
    Push(S, 5, 1);

    i = Pop(S, 1);
    printf("Pop %d\n", i);
    i = Pop(S, 1);
    printf("Pop %d\n", i);
    i = Pop(S, 1);
    printf("Pop %d\n", i);
    i = Pop(S, 1);
    printf("Pop %d\n", i);
    i = Pop(S, 2);
    printf("Pop %d\n", i);
    i = Pop(S, 2);
    printf("Pop %d\n", i);
    i = Pop(S, 2);
    printf("Pop %d\n", i);

    return 0;
}
