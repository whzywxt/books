/** 
 * ���Ա����ʽ�洢ʵ��
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
#define ERROR NULL

typedef int ElementType;
typedef struct LNode *PtrToLNode;

struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position; // �����λ���ǽ��ĵ�ַ
typedef PtrToLNode List;

List MakeEmpty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode)); /* ����ͷ���,��ʹLָ���ͷ��� */
    if (!L)                                 /* �洢����ʧ�� */
        return ERROR;
    L->Next = NULL; /* ָ����Ϊ�� */

    return L;
}

/* ����Ԫ�ص�λ�� O(n) */
Position Find(List L, ElementType X)
{
    Position p = L; // P ָ�� L�ĵ�1�����

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

/* ���� */
List Insert(List L, ElementType X, int i)
{
    Position tmp, pre;

    tmp = (Position)malloc(sizeof(struct LNode)); // ������װ���
    tmp->Data = X;
    if (i == 1)
    {
        // �½������ڱ�ͷ �� ���ر�ͷָ��
        tmp->Next = L;
        return tmp;
    }
    else
    {
        // �������Ϊ i-1 �Ľ��
        int cnt = 1; // λ���1��ʼ
        pre = L;     // ָ��L�ĵ�1�����
        while (pre && cnt < i - 1)
        {
            pre = pre->Next;
            cnt++;
        }

        // ���ҽ�㲻��L��
        if (pre == NULL || cnt != i - 1)
        {
            printf("����λ�ò�������\n");
            free(tmp);
            return ERROR;
        }
        else
        {
            // �ҵ��˴������ǰһ�����pre, �����½�� �����ر�ͷL
            tmp->Next = pre->Next;
            pre->Next = tmp;
            return L;
        }
    }
}

bool Insert2(List L, ElementType X, int i)
{
    // Ĭ��L��ͷ���
    Position tmp, pre;
    int cnt = 0;

    // ����λ��Ϊi-1�Ľ��
    pre = L; // preָ���ͷ
    while (pre && cnt < i - 1)
    {
        pre = pre->Next;
        cnt++;
    }

    // ���ҽ�㲻��L��
    if (pre == NULL || cnt != i - 1)
    {
        printf("����λ�ò�������\n");
        return false;
    }
    else
    {
        // �ҵ��˴�������ǰһ����� pre,�� i Ϊ 1, pre ��ָ���ͷ
        tmp = (Position)malloc(sizeof(struct LNode)); // ���� ��װ���
        tmp->Data = X;
        tmp->Next = pre->Next;
        pre->Next = tmp;
        return true;
    }
}

/* ɾ�� */
bool Delete(List L, int i)
{
    // Ĭ��L��ͷ���
    Position tmp, pre;
    int cnt = 0;

    // ����λ��Ϊi-1�Ľ��
    pre = L; // pre ָ���ͷ
    while (pre && cnt < i - 1)
    {
        pre = pre->Next;
        cnt++;
    }

    if (pre == NULL || cnt != i - 1 || pre->Next == NULL)
    {
        printf("����λ�ò�������\n");
        return false;
    }
    else
    {
        // �ҵ���ɾ������ǰһ�����pre, Ȼ��ɾ�����
        tmp = pre->Next;
        pre->Next = tmp->Next;
        free(tmp);
        return true;
    }
}

/* ���� */
int Length(List L)
{
    Position p;
    int cnt = 0; // ��ʼ��������
    p = L->Next; // p ָ���ĵ�һ�����
    while (p)
    {
        p = p->Next;
        cnt++; // ��ǰpָ���cnt�����
    }

    return cnt;
}

/* ����ָ����λ��K������L����Ӧ */
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

/* ��ʼ���������Ա�L�Ѵ��� */
/* ������������ζ�L��ÿ������Ԫ����� */
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
    printf("��ʼ��L��Length(L)=%d\n", Length(L));
    for (j = 1; j <= 10; j++)
    {
        // L = Insert(L, j, 1);
        Insert2(L, j, 1);
    }
    printf("��L�ı�ͷ���β���1��10��Length(L)=%d, L.data=", Length(L));
    ListTraverse(L);

    // L = MakeEmpty();
    // for (j = 1; j <= 10; j++)
    //     Insert2(L, j, j);
    // printf("��L�ı�β���β���1��10��Length(L)=%d, L.data=\n", Length(L));
    // ListTraverse(L);

    // Insert2(L, 0, 1);
    // printf("��L�ı�ͷ����0��Length(L)=%d, L.data=\n", Length(L));
    // ListTraverse(L);

    // p = Find(L, 5);
    // if (NULL == p)
    // {
    //     printf("û���ҵ�ֵΪ %d ��Ԫ��\n", 5);
    // }
    // else
    // {
    //     printf("�ҵ�ֵΪ %d ��Ԫ��\n", p->Data);
    // }

    printf("\n---����Ԫ��ֵ---\n");
    for (j = 1; j <= 14; j++)
    {
        k = FindKth(L, j);
        if (-1 != k)
            printf("�� %d ��Ԫ�ص�ֵΪ��%d\n", j, k);
        else
            printf("û��ֵΪ %d ��Ԫ��\n", j);
    }

    return 0;
}
