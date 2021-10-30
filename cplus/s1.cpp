/**
1. 设计一个Bank类，实现银行某账号的资金往来账目管理，包括建账号、存入、取出等。
解：Bank类包括私有数据成员top(当前账指针)，date(日期)，money(金额)，rest(余额)和sum(累计余额)。
另有一个构造函数和三个成员函数bankin()(处理存入账)，bankout()处理取出账)和disp() (输出明细账)。
本题程序如下：
*/
#include <stdio.h>
#include <string.h>

#define Max 100
class Bank
{
    int top;
    char date[Max][10]; // 日期
    int money[Max];     // 金额
    int rest[Max];      // 余额
    static int sum;     // 累计余额
public:
    Bank() { top = 0; }
    void bankin(const char d[], int m)
    {
        strcpy(date[top], d);
        money[top] = m;
        sum = sum + m;
        rest[top] = sum;
        top++;
    }
    void bankout(const char d[], int m)
    {
        strcpy(date[top], d);
        money[top] = -m;
        sum = sum - m;
        rest[top] = sum;
        top++;
    }
    void disp();
};

int Bank::sum = 0;
void Bank::disp()
{
    int i;
    // printf("  日期存入   取出余额\n");
    printf("    Date  deposit  withdraw  balance\n");
    for (i = 0; i < top; i++)
    {
        printf("%8s", date[i]);
        if (money[i] < 0)
            printf("         %6d", -money[i]);
        else
            printf("%6d         ", money[i]);
        printf("    %6d\n", rest[i]);
    }
}

int main()
{
    Bank obj;
    obj.bankin("2001.2.5", 1000);
    obj.bankin("2001.3.2", 2000);
    obj.bankout("2001.4.1", 500);
    obj.bankout("2001.4.5", 800);
    obj.disp();
}

/*本程序的执行结果如下：
    Date  deposit  withdraw  balance
2001.2.5  1000               1000
2001.3.2  2000               3000
2001.4.1            500      2500
2001.4.5            800      1700
*/