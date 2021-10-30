/*6、下面的文件stack.h是一个堆栈类模板Stack的完整实现。在这个文件中，首先定义了一个堆栈元素类模板StackItem，然后，
在这个类的基础上定义了堆栈类模板Stack。在Stack中使用链表存放堆栈的各个元素，top指针指向链表的第一个节点元素，
bottom指针指向链表的最后一个节点元素，成员函数push()将一个新节点元素加入（压进）到堆栈顶部，pop()从堆栈顶部删除（弹出）一个节点元素。
为方便起见，程序中加上了行号。阅读程序，根据程序后面的问题作出相应解答。填写A-E空白处的答案
*/
  
1.         /*---------------------------------------------------------- -------------------*/
2.         /********************* 文件stack.h ************************/
3.         /*---------------------------------------------------------- -------------------*/
4.         template <class Type>
5.         class Stack;
6.         /***************** 定义模板类StackItem ******************/
7.         template<class Type>
8.         class StackItem
9.         {
10.       public:
11.         StackItem(const Type & elem):item(elem) {}
12.         ~StackItem() {}
13.       private:
14.         Type item;
15.         StackItem * nextItem;
16.       friend  class Stack<Type>;
17.     };
18.     /***************** 定义模板类Stack *********************/
19.     template <class Type>
20.     class Stack
21.     {
22.       public:
23.         Stack():top( NULL), ____(A)_____ {}
24.         ~Stack();
25.         Type pop();
26.         void push(const Type &);
27.         bool is_empty() const { return ____(B) ______ ; }
28.       private:
29.         StackItem<Type> * top;
30.         StackItem<Type> * bottom;
31.     };
32.     //模板类Stack的函数成员pop()的实现。
33.     //从堆栈顶弹出一个节点，并返回该节点的值
34.     template<class Type>
35.     Type Stack<Type>::pop()
36.     {
37.       StackItem<Type> *ptop;      //指向顶部节点的临时指针
38.       Type retVal;	                 //返回值
39.       ______(C) ________;
40.       retVal = top->item;
41.       top = top->nextItem;
42.       delete ptop;
43.       return retVal;
44.     }
45.     //模板类Stack的函数成员push()的实现
46.     template<class Type>
47.     void Stack<Type>::push(const Type & newItem)
48.     {
49.       StackItem<Type> *pNew = new StackItem<Type>( newItem);
50.         ______(D)___________;
51.       if (bottom == NULL)  bottom = top = pNew;
52.       else   _____(E)_________;
53.     }
54.     //模板类Stack的析构函数~Stack()的实现
55.     template<class Type>
56.     Stack<Type>::~Stack()
57.     {
58.       StackItem<Type> *p = top, *q;
59.       while(p != NULL) {
60.         q = p->nextItem;
61.         delete p;
62.         p = q;
63.       }
64.     }

/*
问题A-E： 程序中有几处填空，将它们完成。 
(A)        bottom (NULL)
(B)         top == NULL;
(C)        ptop = top;
(D)        pNew->nextItem = top;
(E)         top = pNew;
*/