#include <stdio.h>
#include <ctype.h>

#define RATE1 0.13230
#define RATE2 0.15040
#define RATE3 0.30025
#define RATE4 0.34025

#define BREAK1 360.0 // ���ʵĵ�1���ֽ��
#define BREAK2 468.0 // ���ʵĵ�2���ֽ��
#define BREAK3 720.0 // ���ʵĵ�3���ֽ��
#define BASE1 (RATE1 * BREAK1) // ʹ��360kwh�ķ���
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1))) // ʹ��468kwh�ķ���
#define BASE3 (BASE1 + BASE2 + (RATE3 *(BREAK3 - BREAK2))) // ʹ��720kwh�ķ���

int main(void)
{
double kwh; // ʹ�õ�ǧ��ʱ
double bill;// ���
printf("Please enter the kwh used.\n");
scanf("%lf", &kwh); // %lf��Ӧdouble����
if (kwh <= BREAK1)
bill = RATE1 * kwh;
else if (kwh <= BREAK2) // 360��468 kwh
bill = BASE1 + (RATE2 * (kwh - BREAK1));
else if (kwh <= BREAK3) // 468��720 kwh
bill = BASE2 + (RATE3 * (kwh - BREAK2));
else// ���� 720 kwh
bill = BASE3 + (RATE4 * (kwh - BREAK3));
printf("The charge for %.1f kwh is $%1.2f.\n", kwh, bill);
return 0;
}


