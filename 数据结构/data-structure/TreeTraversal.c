/**
 * 先序遍历
 * 
 * 访问根节点
 * 先序遍历其左子树
 * 先序遍历其后子树
 */
void PreorderTraversal(BinTree BT)
{
    if (BT)
    {
        printf("%d ", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

/**
 * 中序遍历
 * 
 * 中序遍历其左子树
 * 访问根节点
 * 中序遍历其右子树
 */
void InorderTraversal(BinTree BT)
{
    if (BT)
    {
        InorderTraversal(BT->Left);
        /* 此处假设对BT结点的访问就是打印数据 */
        printf("%d ", BT->Data); /* 假设数据为整型 */
        InorderTraversal(BT->Right);
    }
}

/**
 * 后序遍历
 * 
 * 后序遍历其左子树
 * 后序遍历其右子树
 * 访问根节点
 */
void PostorderTraversal(BinTree BT)
{
    if (BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf("%d ", BT->Data);
    }
}
