//
//  main.cpp
//  f-二叉排序树
//
//  Created by ZYJ on 16/7/27.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

typedef bool Status;

//  二叉树的二叉链表结点结构定义
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//  递归查找二叉排序树T中是否存在Key
//  指针f指向T的双亲，其初始值调用值为NULL
//  若查找成功，则指针p指向该数据元素结点，并返回TRUE
//  否则指针p指向查找路径上访问的最后一个结点，并返回FALSE
Status SearchBST(BiTree T, int Key, BiTree f, BiTree *p)
{
    if (!T) //  查找不成功
    {
        *p = f;
        return false;
    }
    else if (Key == T->data)
    {
        *p = T;
        return true;
    }
    else if (Key < T->data)
    {
        return SearchBST(T->lchild, Key, T, p);
    }
    else
    {
        return SearchBST(T->rchild, Key, T, p);
    }
}

//  当二叉排序树T中不存在关键字等于Key的数据元素时，
//  插入Key并返回TRUE，否则返回FALSE
Status InserBST(BiTree *T, int Key)
{
    BiTree p, s;
    if (!SearchBST(*T, Key, NULL, &p))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = Key;
        s->lchild = s->rchild = NULL;
        
        if (!p)             
        {
            *T = s;         //  插入s为新的根结点
        }
        else if (Key < p->data)
        {
            p->lchild = s;  //  插入s为左孩子
        }
        else
        {
            p->rchild = s;  //  插入s为右孩子
        }
        return true;
    }
    else
    {
        return false;       //  树中已有关键字相同的结点，不再插入
    }
}

//  删除操作
Status Delete(BiTree *p)
{
    BiTree q, s;
    
    if ((*p)->rchild == NULL)       //  右子树为空 || 叶子结点
    {
        q = *p;
        (*p) = (*p)->lchild;
        free(q);
    }
    else if ((*p)->lchild == NULL)  //  左子树为空
    {
        q = *p;
        (*p) = (*p)->rchild;
        free(q);
    }
    else                            //  p直接前驱（左子树的最右后代）
    {
        q = *p;
        s = (*p)->lchild;
        
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        
        (*p)->data = s->data;       //  直接进行数据的替换
        
        if (q != *p)
        {
            q->rchild = s->lchild;
        }
        else
        {
            q->lchild = s->lchild;
        }
        
        free(s);
    }
    return true;
}

//  当二叉排序树T中存在关键字Key的数据元素时，
//  删除Key并返回TRUE，否则返回FALSE
Status DeleteBST(BiTree *T, int Key)
{
    if (!*T)
    {
        return false;
    }
    else
    {
        if (Key == (*T)->data)
        {
            return Delete(T);
        }
        else if (Key < (*T)->data)
        {
            return DeleteBST(&(*T)->lchild, Key);
        }
        else
        {
            return DeleteBST(&(*T)->rchild, Key);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
