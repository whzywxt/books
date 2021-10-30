#include <stddef.h>

typedef struct node
{
    DataType data;
    struct node *next
} LinkNode, *LinkList;

void selectsort(LinkList head)
{
    ListNode *p, *min, *q, *r;
    p = head;
    r = head->next;
    while (r->next != NULL)
    {
        min = r;
        q = r->next;
        while (q != NULL)
        {
            if (q->data < min->data)
                min = q;
            q = q->next;
        }
        t = r->data;
        r->data = min->data;
        min->data = t;
        p = r;
        r = r->next;
    }
}

