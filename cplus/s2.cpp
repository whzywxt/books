/*
2．写一个函数，找出给定字符串中大写字母字符（即’A’-‘Z’这26个字母）的个数（如字符串”China Computer Wrold”中大写字母字符的个数为3个）。
*/
#include <iostream>
using namespace std;

int CalcCapital(const char *str)
{
    if (str == NULL)
        return 0; //判断字符指针是否为空

    int num_of_Capital = 0; //记录大写字母字符个数的变量，初值为0

    for (int i = 0; str[i] != 0x0; i++) 
        if (str[i] >= 'A' && str[i] <= 'Z')
            num_of_Capital++; //若是大写字母，则总数加1

    return num_of_Capital; //返回大写字母字符数
}

int main()
{
    int i;
    i = CalcCapital("China Computer Wrold");

    printf("%d\n", i);
    return 0;
}
