#include <stddef.h>

typedef struct node
{
    DataType data;
    struct node *next
} LinkNode, *LinkList;

void delete (LinkList A, LinkList B)
{
    LinkList pa, pb, p;
    pa = A;
    pb = B->next;
    p = pa->next;

    while (p != NULL)
    {
        while (pb != NULL)
        {
            if (pb->data = p->data)
            {
                break;
            }

            pb = pb->next;
        }

        if (pb != NULL)
        {
            pa->next = p->next;
            delete p;
            p = pa->next;
        }
        else
        {
            pa = p;
            p = p->next;
        }

        pb = B->next;
    }
}

void DelEqual(LinkList La,LinkList Lb){    //伪代码
	// La 和 Lb 分别存放 A 和 B 有序链表的头指针
	LinkList pa,pb,r;	    // r指向要删除的结点
	pa = La;				// pa指向A的头结点
	pb = Lb->next;			// pb指向B的头结点的下一个结点
	while(pa->next&&pb){	// 循环条件：pa->next和pb所指的结点都存在
		if(pa->next->data < pb->data)
			pa = pa->next;
		else{
			//下面为什么用while，而不用if，后面的例子可以解释
			while(pa->next->data == pb->data){
				r = pa->next;
				pa->next = r->next;
				free(r);
			}
			pb = pb->next;
		}
	}
}
