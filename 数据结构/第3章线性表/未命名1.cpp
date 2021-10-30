#include "stdio.h" 
#include "time.h"
#include "stdlib.h"  

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */

typedef struct
{
	ElemType data[MAXSIZE];        /* 数组，存储数据元素 */
	int length;                                /* 线性表当前长度 */
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
