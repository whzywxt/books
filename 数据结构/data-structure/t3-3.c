#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;
#include "45110-A0/3-10-4.h"

#define ERROR -1;

// Ë³ÐòÕ»µÄ´´½¨
Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;

    return S;
}

bool IsFull(Stack S)
{
    return (S->Top == S->MaxSize - 1);
}

bool Push(Stack S, ElementType X)
{
    if (IsFull(S))
    {
        printf("¶ÑÕ»Âú\n");
        return false;
    }
    else
    {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty(Stack S)
{
    return (S->Top == -1);
}

ElementType Pop(Stack S)
{
    if (IsEmpty(S))
    {
        printf("¶ÑÕ»¿Õ\n");
        return ERROR;
    }
    else
    {
        return (S->Data[(S->Top)--]);
    }
}

int main()
{
    Stack S = CreateStack(5);
    ElementType i;

    Push(S, 1);
    Push(S, 10);
    Push(S, 100);

    // i = Pop(S);
    // printf("Pop %d\n", i);
    // i = Pop(S);
    // printf("Pop %d\n", i);

    Push(S, 1000);
    Push(S, 10000);
    Push(S, 100000);
    Push(S, 10000000);
    Push(S, 5);

    i = Pop(S);
    printf("Pop %d\n", i);
    i = Pop(S);
    printf("Pop %d\n", i);
    i = Pop(S);
    printf("Pop %d\n", i);
    i = Pop(S);
    printf("Pop %d\n", i);
    i = Pop(S);
    printf("Pop %d\n", i);
    i = Pop(S);
    printf("Pop %d\n", i);

    return 0;
}
