#include <stdio.h>
typedef int ElementType;

// 求 N 个集合元素 S[] 中的最大值
ElementType Max(ElementType S[], int N)
{
    int i;
    ElementType CurMax = S[0];

    for (i = 0; i < N; i++)
    {
        if (S[i] > CurMax)
        {
            CurMax = S[i];
        }
    }

    return CurMax;
}

typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Reverse(List L)
{
    PtrToNode Old_head, New_head, Temp;

    Old_head = L;    // 初始化当前旧表头为 L
    New_head = NULL; // 初始化逆转后新表头为空
    // 当旧表不为空时
    while (Old_head)
    {
        Temp = Old_head->Next;
        Old_head->Next = New_head;
        New_head = Old_head; // 将当前旧表头逆转为新表头
        Old_head = Temp;     // 更新旧表头
    }

    L = New_head; // 更新 L
    return L;
}

ElementType Median(ElementType A[], int N)
{
    int i, j, MaxPosition;
    ElementType TmpA;

    for (i = 0; i < N - 1; i++)
    {
        MaxPosition = i;
        for (j = i + 1; j < N; j++)
        {
            // 找出最大值的下标
            if (A[j] > A[MaxPosition])
                MaxPosition = j;
        }

        // 将最大值与待排序列的第一个元素A[i]交换
        TmpA = A[i];
        A[i] = A[MaxPosition];
        A[MaxPosition] = TmpA;
    } // 排序结束
    printN(A, N);

    // 数组中下标为 (N-1)/2 位置的元素就是序列中第 N/2 个元素
    return A[(N - 1) / 2];
}

ElementType printN(ElementType A[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("A[%d] = %d\n", i, A[i]);
    }
}

void Swap(int *X, int *Y)
{
    int tmp;
    tmp = *X;
    *X = *Y;
    *Y = tmp;
}

double Factorial(int N)
{
    // if (N == 0)
    //     return 1;
    // else
    // {
    //     return N * Factorial(N - 1);
    // }
    int n;
    double sum, x;
    for (n = 1, sum = 0, x = 1; n <= N; n++)
    {
        x *= n;
        // sum += x;
        printf("%2d! = %.0lf\n ", n, x); //LF
    }
}

// n 金片个数, A 起始针 --> B 目标针 --> C 过渡针
void Move(int n, int start, int goal, int temp)
{
    // if (n <= 0)
    // {
    //     return;
    // }
    if (n > 1)
    {
        // A --> C --> B
        Move(n - 1, start, temp, goal);
        // printf("Move disk %d from %d to %d.\n", n, start, goal);
        // C --> B --> A
        Move(n - 1, temp, goal, start);
    } else if (n == 1) {
        printf("Move disk %d from %d to %d.\n", n, start, goal);
    }
    // 当 n==1 时 do nothing
}

int main()
{
    // ElementType a[5] = {1, 20, 30, 40, 5};
    // Factorial(40);
    // printf("%d\n", Factorial(15));

    // union key
    // {
    //     int k;
    //     char ch[2];
    // } u;

    // u.k = 258;
    // printf("%d %d %d\n", u.ch[0], u.ch[1], u.k);

    // int X = 10, Y = 20;
    // Swap(&X, &Y);
    // printf("X = %d, Y = %d\n", X, Y);

    // 将 64 个金片从1号针移到3号针, 2号针为过渡针
    // 转变为 将63个金片从1号针到2号针,将3号针为过渡针
    // 转变为 将63个金片从2号针到3号针,将1号针为过渡针
    // ...递归下去
    Move(64, 1, 3, 2);

    return 0;
}