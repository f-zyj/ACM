//
//  main.cpp
//  f-平衡二叉树
//
//  Created by ZYJ on 16/7/28.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

#define LH 1
#define EH 0
#define RH -1

//  AVL

//  结点
typedef struct BiTNode
{
    int data;
    int bf;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//  右旋
void R_Rotate(BiTree *p)
{
    BiTree L;
    L = (*p)->lchild;
    (*p)->lchild = L->rchild;
    L->rchild = (*p);
    *p = L;
    return ;
}

//  左旋
void L_Rotate(BiTree *p)
{
    BiTree L;
    L = (*p)->rchild;
    (*p)->rchild = L->lchild;
    L->lchild = (*p);
    *p = L;
    return ;
}

//  左边深旋转
void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild;
    
    switch (L->bf)
    {
        case LH:
            (*T)->bf = L->bf = EH;
            R_Rotate(T);            //  右旋即可
            break;
        case RH:
            Lr = L->rchild;
            switch (Lr->bf)
            {
                case LH:
                    (*T)->bf = RH;
                    L->bf = EH;
                    break;
                case EH:
                    (*T)->bf = L->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
            }
            Lr->bf = EH;
            L_Rotate(&(*T)->lchild);//  先左旋
            R_Rotate(T);            //  后右旋
            break;
    }
    return ;
}

//  右边深旋转
void RightBalance(BiTree *T)
{
    BiTree L, Ll;
    L = (*T)->rchild;
    
    switch (L->bf)
    {
        case RH:
            (*T)->bf = L->bf = EH;
            L_Rotate(T);            //  左旋即可
            break;
        case LH:
            Ll = L->lchild;
            switch (Ll->bf)
            {
                case LH:
                    (*T)->bf = RH;
                    L->bf = EH;
                    break;
                case EH:
                    (*T)->bf = L->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
            }
            Ll->bf = EH;
            R_Rotate(&(*T)->rchild);//  先右旋
            L_Rotate(T);            //  后左旋
            break;
    }
    return ;
}

//  插入AVL结点
bool InsertAVL(BiTree *T, int e, bool *taller)
{
    if (!*T)
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = true;
    }
    else
    {
        if (e == (*T)->data)    //  已经存在e
        {
            *taller = false;
            return false;
        }
        if (e < (*T)->data)     //  小于data向左递归
        {
            if (!InsertAVL(&(*T)->lchild, e, taller))
            {
                return false;
            }
            switch ((*T)->bf)
            {
                case LH:    //  左边深，插入前需要旋转
                    LeftBalance(T);
                    *taller = false;
                    break;
                case EH:    //  平衡，插入后变为左边深
                    (*T)->bf = LH;
                    break;
                case RH:    //  右边深，插入后变为平衡
                    (*T)->bf = EH;
                    *taller = false;
                    break;
            }
        }
        else                    //  大于data向右递归
        {
            if (!InsertAVL(&(*T)->rchild, e, taller))
            {
                return false;
            }
            switch ((*T)->bf)
            {
                case LH:    //  左边深，插入后变为平衡
                    (*T)->bf = EH;
                    *taller = false;
                    break;
                case EH:    //  平衡，插入后变为右边深
                    (*T)->bf = RH;
                    break;
                case RH:    //  右边深，插入前需要旋转
                    RightBalance(T);
                    *taller = false;
                    break;
            }
        }
    }
    return *taller;
}


int main(int argc, const char * argv[])
{
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
