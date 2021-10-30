#include <stdio.h>
typedef int ElementType;

void Swap(ElementType *X, ElementType *Y)
{
    ElementType tmp;

    tmp = *X;
    *X = *Y;
    *Y = tmp;
}

ElementType FindKthLargest(ElementType S[],int K,int Left,int Right)
{
    ElementType e=S[Left];
    int L=Left;
    int R=Right;

    while (1)
    {
        while (( Left <= Right ) && e < S[Left])
        {
            Left++;
        }
        
    }
    
}

// ABC 按循序进栈 出栈 3!=6 种组合 CAB 出栈顺序不可能
// ABC A进出 B进出 C进出
// ACB A进出 B进 C进出 B出
// BAC A进 B进出 A出 C进出
// BCA A进 B进出 C进出 A出
// CBA A进 B进 C进出 B出 A出
// CAB 不可能

// ABCB 按循序进栈 出栈 4!=24 种组合
// A BCD A进出 B进出 C进出 D进出
// A BDC A进出 B进出 C进 D进出 C出
// A CBD A进出 B进 C进出 B出 D进出
// A CDB A进出 B进 C进出 D进出 B出
// A DBC A进出 不可能
// A DCB A进出 B进 C进 D进出 C出 B出

// B ACD A进 B进出 A出 C进出 D进出
// B ADC A进 B进出 A出 C进 D进出 C出
// B CAD A进 B进出 C进出 A出 D进出
// B CDA A进 B进出 C进出 D进出 A出
// B DAC A进 B进出 C进 D进出 不可能
// B DCA A进 B进出 C进 D进出 C出 A出

// C ABD AB进 C进出 不可能
// C ADB AB进 C进出 不可能
// C BAD AB进 C进出 B出 A出 D进出
// C BDA AB进 C进出 B出 D进出 A出
// C DAB AB进 C进出 不可能
// C DBA AB进 C进出 D进出 B出 A出

// D ABC ABC进 D进出 不可能
// D ACB ABC进 D进出 不可能
// D BAC ABC进 D进出 不可能
// D BCA ABC进 D进出 不可能
// D CAB ABC进 D进出 不可能
// D CBA ABC进 D进出 C出 B出 A出