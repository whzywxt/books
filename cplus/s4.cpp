/*
给定新数值，在一个按节点所存放数值从大到小排序的链表中，找适当位置插一个新节点，仍保持有序的链表，写一个函数，完成此操作。
*/
#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
    int Value;  //存放数值
    Node *next; //指向链表中的下一个节点
};

Node *insNode(Node *head, int newValue)
{

    Node *newNode = new Node; //申请新的节点空间
    if (newNode == NULL)
        return NULL; //

    newNode->data = newValue; //填充新节点的内容
    newNode->next = NULL;

    Node *pre, *cur;
    Pre = head;

    if (head == NULL)
        head = newNode; //插入到空链表的表头
    else if (newValue >= head->Value)
    {
        newNode->next = head;
        head = newNode; //插入到链表的表头
    }
    else
    { //在链表寻找插入点
        Node *cur, *pre = head;
        while (pre->next != NULL)
        {
            cur = pre->next;
            if (newValue >= cur->Value)
                break;
            else
                pre = cur;
        }
        if (pre->next != NULL)
            newNode->next = cur; //若非末尾，则有下一节点
        pre->next = newNode;     //将新节点插入
    }
}
return head;
}