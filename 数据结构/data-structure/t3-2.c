/** 
 * 线性表的链式存储实现
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
#define ERROR NULL

typedef int ElementType;
typedef struct LNode *PtrToLNode;

struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position; // 这里的位置是结点的地址
typedef PtrToLNode List;

List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode)); /* 产生头结点,并使L指向此头结点 */
    if (!L)                                 /* 存储分配失败 */
        return ERROR;
    L->Next = NULL; /* 指针域为空 */

    return L;
}

/* 查找元素的位置 O(n) */
Position Find(List L, ElementType X)
{
    Position p = L; // P 指向 L的第1个结点

    while (p && p->Data != X)
    {
        p = p->Next;
    }

    if (p)
    {
        return p;
    }
    else
    {
        return ERROR;
    }
}

/* 插入 */
List Insert(List L, ElementType X, int i)
{
    Position tmp, pre;

    tmp = (Position)malloc(sizeof(struct LNode)); // 申请填装结点
    tmp->Data = X;
    if (i == 1)
    {
        // 新结点插入在表头 并 返回表头指针
        tmp->Next = L;
        return tmp;
    }
    else
    {
        // 查找序号为 i-1 的结点
        int cnt = 1; // 位序从1开始
        pre = L;     // 指向L的第1个结点
        while (pre && cnt < i - 1)
        {
            pre = pre->Next;
            cnt++;
        }

        // 所找结点不在L中
        if (pre == NULL || cnt != i - 1)
        {
            printf("插入位置参数错误\n");
            free(tmp);
            return ERROR;
        }
        else
        {
            // 找到了待插结点的前一个结点pre, 插入新结点 并返回表头L
            tmp->Next = pre->Next;
            pre->Next = tmp;
            return L;
        }
    }
}

bool Insert2(List L, ElementType X, int i)
{
    // 默认L有头结点
    Position tmp, pre;
    int cnt = 0;

    // 查找位序为i-1的结点
    pre = L; // pre指向表头
    while (pre && cnt < i - 1)
    {
        pre = pre->Next;
        cnt++;
    }

    // 所找结点不在L中
    if (pre == NULL || cnt != i - 1)
    {
        printf("插入位置参数错误\n");
        return false;
    }
    else
    {
        // 找到了待插入结点前一个结点 pre,若 i 为 1, pre 就指向表头
        tmp = (Position)malloc(sizeof(struct LNode)); // 申请 填装结点
        tmp->Data = X;
        tmp->Next = pre->Next;
        pre->Next = tmp;
        return true;
    }
}

/* 删除 */
bool Delete(List L, int i)
{
    // 默认L有头结点
    Position tmp, pre;
    int cnt = 0;

    // 查找位序为i-1的结点
    pre = L; // pre 指向表头
    while (pre && cnt < i - 1)
    {
        pre = pre->Next;
        cnt++;
    }

    if (pre == NULL || cnt != i - 1 || pre->Next == NULL)
    {
        printf("插入位置参数错误\n");
        return false;
    }
    else
    {
        // 找到待删除结点的前一个结点pre, 然后删除结点
        tmp = pre->Next;
        pre->Next = tmp->Next;
        free(tmp);
        return true;
    }
}

/* 长度 */
int Length(List L)
{
    Position p;
    int cnt = 0; // 初始化计数器
    p = L->Next; // p 指向表的第一个结点
    while (p)
    {
        p = p->Next;
        cnt++; // 当前p指向第cnt个结点
    }

    return cnt;
}

/* 根据指定的位序K，返回L中相应 */
ElementType FindKth(List L, int K)
{
    Position p;
    int cnt = 1;
    p = L->Next;
    while (p && cnt < K)
    {
        p = p->Next;
        cnt++;
    }

    if ((cnt == K) && p)
    {
        return p->Data;
    }
    else
    {
        return -1;
    }
}

bool visit(ElementType v)
{
    printf("%d ", v);
    return true;
}

/* 初始条件：线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
bool ListTraverse(List L)
{
    List p = L->Next;
    while (p)
    {
        visit(p->Data);
        p = p->Next;
    }
    printf("\n");
    return true;
}

int main()
{
    List L;
    int j, k;
    Position p;

    L = MakeEmpty();
    printf("初始化L后：Length(L)=%d\n", Length(L));
    for (j = 1; j <= 10; j++)
    {
        // L = Insert(L, j, 1);
        Insert2(L, j, 1);
    }
    printf("在L的表头依次插入1～10后：Length(L)=%d, L.data=", Length(L));
    ListTraverse(L);

    // L = MakeEmpty();
    // for (j = 1; j <= 10; j++)
    //     Insert2(L, j, j);
    // printf("在L的表尾依次插入1～10后：Length(L)=%d, L.data=\n", Length(L));
    // ListTraverse(L);

    // Insert2(L, 0, 1);
    // printf("在L的表头插入0后：Length(L)=%d, L.data=\n", Length(L));
    // ListTraverse(L);

    // p = Find(L, 5);
    // if (NULL == p)
    // {
    //     printf("没有找到值为 %d 的元素\n", 5);
    // }
    // else
    // {
    //     printf("找到值为 %d 的元素\n", p->Data);
    // }

    printf("\n---查找元素值---\n");
    for (j = 1; j <= 14; j++)
    {
        k = FindKth(L, j);
        if (-1 != k)
            printf("第 %d 个元素的值为：%d\n", j, k);
        else
            printf("没有值为 %d 的元素\n", j);
    }

    return 0;
}
