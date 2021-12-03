/** 
线性表的定义与实现 
1.	List MakeEmpty()：初始化一个新的空线性表。
2.	ElementType FindKth( List L, int K )：根据指定的位序K，返回L中相应元素。
3.	Position Find( List L, ElementType X )：已知X，返回线性表L中与X相同的第一个元素的位置；若不存在则返回错误信息。
4.	bool Insert( List L, ElementType X, Position P )：在L的指定位置P前插入一个新元素X；成功则返回true，否则返回false。
5.	bool Delete( List L, Position P )：从L中删除指定位置P的元素；成功则返回true，否则返回false。
6.	int Length( List L )：返回线性表L的长度。
*/
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 11 /* 存储空间初始分配量 */
#define ERROR -1

typedef int ElementType;
typedef int Position;
typedef struct LNode *PtrToLNode;

struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last;
};
typedef PtrToLNode List;

/* 1.顺序表的初始化 */
List MakeEmpty()
{
    List L;

    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;

    return L;
}

/* 查找元素的位置 */
Position Find(List L, ElementType X)
{
    Position i = 0;

    while (i <= L->Last && L->Data[i] != X)
        i++;
    if (i > L->Last)
        return ERROR; /* 如果没找到，返回错误信息 */
    else
        return i; /* 找到后返回的是存储位置 */
}

/* 插入 */
bool Insert(List L, ElementType X, int i)
{
    /* 在L的指定位序i前插入一个新元素X;位序i元素的数组位置下标是i-1 */
    Position j;

    if (L->Last == MAXSIZE - 1)
    {
        /* 表空间已满，不能插入 */
        printf("表满\n");
        return false;
    }
    if (i < 1 || i > L->Last + 2)
    {
        /* 检查插入位序的合法性：是否在1~n+1。n为当前元素个数，即Last+1 */
        printf("位序不合法\n");
        return false;
    }
    for (j = L->Last; j >= i - 1; j--) /*Last指向序列最后元素 */
        L->Data[j + 1] = L->Data[j];   /* 将位序i及以后的元素顺序向后移动 */
    L->Data[i - 1] = X;                /* 新元素插入第i位序，其数组下标为i-1 */
    L->Last++;                         /* Last仍指向最后元素 */
    return true;
}

/* 删除 */
bool Delete(List L, int i)
{
    /* 从L中删除指定位序i的元素,该元素数组下标为i-1 */
    Position j;

    if (i < 1 || i > L->Last + 1)
    {
        /* 检查空表及删除位序的合法性 */
        printf("位序%d不存在元素\n", i);
        return false;
    }
    for (j = i; j <= L->Last; j++)
        L->Data[j - 1] = L->Data[j]; /*将位序i+1及以后的元素顺序向前移动*/
    L->Last--;                       /* Last仍指向最后元素 */
    return true;
}

int Length(List L)
{
    return L->Last + 1;
}

/* 根据指定的位序K，返回L中相应 */
ElementType FindKth(List L, int K)
{
    if (K < 1 || K > L->Last + 1)
    {
        printf("位序 [%d] 不存在元素\n", K);
        return ERROR;
    }

    return L->Data[K];
}

bool visit(int i, ElementType v)
{
    printf("位序 [%d] 值为：%d\n", i, v);
    return true;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
bool ListTraverse(List L)
{
    int i, j;
    j = Length(L);
    for (i = 0; i < j; i++)
        visit(i, L->Data[i]);
    printf("\n");
    return true;
}

int main()
{
    List L;
    int i, j;

    L = MakeEmpty();
    printf("初始化L后：Length(L)=%d\n", Length(L));
    for (j = 1; j <= 10; j++)
        Insert(L, j, 1);
    printf("在L的表头依次插入1～10后：Length(L)=%d, L.data=\n", Length(L));
    ListTraverse(L);

    L = MakeEmpty();
    for (j = 1; j <= 10; j++)
        Insert(L, j, j);
    printf("在L的表尾依次插入1～10后：Length(L)=%d, L.data=\n", Length(L));
    ListTraverse(L);

    Insert(L, 0, 1);
    printf("在L的表头插入0后：Length(L)=%d, L.Last=%d, L.data=\n", Length(L), L->Last);
    ListTraverse(L);

    i = Find(L, 5);
    if (i < 0)
    {
        printf("没有找到值为 %d 的元素\n", 5);
    }
    else
    {
        printf("第 %d 个元素的值为：%d\n", i, 5);
    }

    printf("\n---查找元素值---\n");
    for (j = 0; j <= 14; j++)
    {
        i = FindKth(L, j);
        if (ERROR != i)
            printf("第 %d 个元素的值为：%d\n", j, i);
        // else
        //     printf("没有值为 %d 的元素\n", j);
    }

    return 0;
}
