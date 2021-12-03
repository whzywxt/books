/** 
���Ա�Ķ�����ʵ�� 
1.	List MakeEmpty()����ʼ��һ���µĿ����Ա�
2.	ElementType FindKth( List L, int K )������ָ����λ��K������L����ӦԪ�ء�
3.	Position Find( List L, ElementType X )����֪X���������Ա�L����X��ͬ�ĵ�һ��Ԫ�ص�λ�ã����������򷵻ش�����Ϣ��
4.	bool Insert( List L, ElementType X, Position P )����L��ָ��λ��Pǰ����һ����Ԫ��X���ɹ��򷵻�true�����򷵻�false��
5.	bool Delete( List L, Position P )����L��ɾ��ָ��λ��P��Ԫ�أ��ɹ��򷵻�true�����򷵻�false��
6.	int Length( List L )���������Ա�L�ĳ��ȡ�
*/
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 11 /* �洢�ռ��ʼ������ */
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

/* 1.˳���ĳ�ʼ�� */
List MakeEmpty()
{
    List L;

    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;

    return L;
}

/* ����Ԫ�ص�λ�� */
Position Find(List L, ElementType X)
{
    Position i = 0;

    while (i <= L->Last && L->Data[i] != X)
        i++;
    if (i > L->Last)
        return ERROR; /* ���û�ҵ������ش�����Ϣ */
    else
        return i; /* �ҵ��󷵻ص��Ǵ洢λ�� */
}

/* ���� */
bool Insert(List L, ElementType X, int i)
{
    /* ��L��ָ��λ��iǰ����һ����Ԫ��X;λ��iԪ�ص�����λ���±���i-1 */
    Position j;

    if (L->Last == MAXSIZE - 1)
    {
        /* ��ռ����������ܲ��� */
        printf("����\n");
        return false;
    }
    if (i < 1 || i > L->Last + 2)
    {
        /* ������λ��ĺϷ��ԣ��Ƿ���1~n+1��nΪ��ǰԪ�ظ�������Last+1 */
        printf("λ�򲻺Ϸ�\n");
        return false;
    }
    for (j = L->Last; j >= i - 1; j--) /*Lastָ���������Ԫ�� */
        L->Data[j + 1] = L->Data[j];   /* ��λ��i���Ժ��Ԫ��˳������ƶ� */
    L->Data[i - 1] = X;                /* ��Ԫ�ز����iλ���������±�Ϊi-1 */
    L->Last++;                         /* Last��ָ�����Ԫ�� */
    return true;
}

/* ɾ�� */
bool Delete(List L, int i)
{
    /* ��L��ɾ��ָ��λ��i��Ԫ��,��Ԫ�������±�Ϊi-1 */
    Position j;

    if (i < 1 || i > L->Last + 1)
    {
        /* ���ձ�ɾ��λ��ĺϷ��� */
        printf("λ��%d������Ԫ��\n", i);
        return false;
    }
    for (j = i; j <= L->Last; j++)
        L->Data[j - 1] = L->Data[j]; /*��λ��i+1���Ժ��Ԫ��˳����ǰ�ƶ�*/
    L->Last--;                       /* Last��ָ�����Ԫ�� */
    return true;
}

int Length(List L)
{
    return L->Last + 1;
}

/* ����ָ����λ��K������L����Ӧ */
ElementType FindKth(List L, int K)
{
    if (K < 1 || K > L->Last + 1)
    {
        printf("λ�� [%d] ������Ԫ��\n", K);
        return ERROR;
    }

    return L->Data[K];
}

bool visit(int i, ElementType v)
{
    printf("λ�� [%d] ֵΪ��%d\n", i, v);
    return true;
}

/* ��ʼ������˳�����Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
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
    printf("��ʼ��L��Length(L)=%d\n", Length(L));
    for (j = 1; j <= 10; j++)
        Insert(L, j, 1);
    printf("��L�ı�ͷ���β���1��10��Length(L)=%d, L.data=\n", Length(L));
    ListTraverse(L);

    L = MakeEmpty();
    for (j = 1; j <= 10; j++)
        Insert(L, j, j);
    printf("��L�ı�β���β���1��10��Length(L)=%d, L.data=\n", Length(L));
    ListTraverse(L);

    Insert(L, 0, 1);
    printf("��L�ı�ͷ����0��Length(L)=%d, L.Last=%d, L.data=\n", Length(L), L->Last);
    ListTraverse(L);

    i = Find(L, 5);
    if (i < 0)
    {
        printf("û���ҵ�ֵΪ %d ��Ԫ��\n", 5);
    }
    else
    {
        printf("�� %d ��Ԫ�ص�ֵΪ��%d\n", i, 5);
    }

    printf("\n---����Ԫ��ֵ---\n");
    for (j = 0; j <= 14; j++)
    {
        i = FindKth(L, j);
        if (ERROR != i)
            printf("�� %d ��Ԫ�ص�ֵΪ��%d\n", j, i);
        // else
        //     printf("û��ֵΪ %d ��Ԫ��\n", j);
    }

    return 0;
}
