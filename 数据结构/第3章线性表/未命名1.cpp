#include "stdio.h" 
#include "time.h"
#include "stdlib.h"  

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int ElemType;        /* ElemType���͸���ʵ������������������Ϊint */

typedef struct
{
	ElemType data[MAXSIZE];        /* ���飬�洢����Ԫ�� */
	int length;                                /* ���Ա�ǰ���� */
}LinkList;

void CreateListtail(LinkList *L, int n)
{
	LinkList p,r;
	
	int i;
	
	srand(time(0));
	
	*L = (LinkList)malloc(sizeof(Node))
	
	r = *L;
	
	for (i=0; i<n; i++)
	{
		p=(Node*)malloc(sizeof(Node));
		p->data=rand()%100+1;
		r->next=p;
		r=p;
	}
	r->next= NULL;
	
}
