//
//  main.cpp
//  f-线索二叉树
//
//  Created by ZYJ on 16/6/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

typedef char ElemType;

//  线索存储标志位
//  Link(0)：表示指向左右孩子的指针
//  Thread(1)：表示指向前驱后继的线索
typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild, *rchild;
    PointerTag ltag;
    PointerTag rtag;
} BiThrNode, *BiThrTree;

//  全局变量，始终指向刚刚访问过的结点
BiThrTree pre;

//  创建一棵二叉树，约定用户遵照前序遍历的方式输入数据
void CreateBiThrTree(BiThrTree *T)
{
    char c;
    
    scanf("%c", &c);
    if(' ' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiThrNode *)malloc(sizeof(BiThrNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;
        
        CreateBiThrTree(&(*T)->lchild);
        CreateBiThrTree(&(*T)->rchild);
    }
    return ;
}

//  中序遍历线索化
void InThreading(BiThrTree T)
{
    if(T)
    {
        InThreading(T->lchild);		//  递归左孩子线索化
        
        if(!T->lchild)              //  如果该结点没有左孩子,则用作前驱
        {
            T->ltag = Thread;       //  设置ltag为Thread
            T->lchild = pre;        //  并把lchild指向刚刚访问过的结点
        }
        
        if(!pre->rchild)            //  如果刚刚访问过的结点没有右孩子,则用作后继
        {
            pre->rtag = Thread;     //  设置rtag为Thread
            pre->rchild = T;        //  并把rchild指向正在访问的结点
        }
        
        pre = T;                    //  更新刚刚访问过的结点
        
        InThreading(T->rchild);     //  递归右孩子线索化
    }
    return ;
}

void InOrderThreading(BiThrTree *p, BiThrTree T)
{
    *p = (BiThrTree)malloc(sizeof(BiThrNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    if(!T)                          //  空树则将lchild指向自己
    {
        (*p)->lchild = *p;
    }
    else
    {
        (*p)->lchild = T;
        pre = *p;
        InThreading(T);
        //  调用InThreading()后，pre已经变了，所以需要收尾
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
    return ;
}

void visit(char c)
{
//    printf("%c", c);
    std::cout << c;
    return ;
}

// 中序遍历二叉树，非递归
void InOrderTraverse( BiThrTree T )
{
    BiThrTree p;
    p = T->lchild;
    
    while( p != T )
    {
        while( p->ltag == Link )
        {
            p = p->lchild;
        }
        visit(p->data);
        
        while( p->rtag == Thread && p->rchild != T )
        {
            p = p->rchild;
            visit(p->data);
        }
        
        p = p->rchild;
    }
    
    std::cout << '\n';
    return ;
}

int main()
{
    BiThrTree P, T = NULL;
    //  创建一棵树
    CreateBiThrTree(&T);
    //  将树线索化
    InOrderThreading(&P, T);
    
    std::cout << "中序遍历输出结果为: ";
    //  中序遍历
    InOrderTraverse(P);
    
    return 0;
}