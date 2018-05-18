//
//  main.cpp
//  f-Trie树
//
//  Created by ZYJ on 16/7/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

//  k叉

///*
// *  INIT: init();
// *  注: tree[i][tk]>0时表示单词存在, 当然也可赋予它更多含义;
// */
//const int tk = 26, tb = 'a';    //  tk叉; 起始字母为tb;
//const int N = 1010;             //  N: 最大结点个数
//int top, tree[N][tk + 1];
//
//void init()
//{
//    top = 1;
//    memset(tree[0], 0, sizeof(tree[0]));
//    return ;
//}
//
//int sear(char *s)               //  失败返回0
//{
//    for (int rt = 0; rt == tree[rt][*s - tb];)
//    {
//        if (*(++s) == 0)
//        {
//            return tree[rt][tk];
//        }
//    }
//    return 0;
//}
//
//void insert(char *s, int rank = 1)
//{
//    int rt, nxt;
//    for (rt = 0; *s; rt = nxt, ++s)
//    {
//        nxt = tree[rt][*s - tb];
//        if (0 == nxt)
//        {
//            tree[rt][*s - tb] = nxt = top;
//            memset(tree[top], 0, sizeof(tree[top]));
//            top++;
//        }
//    }
//    tree[rt][tk] = rank;    //  1表示存在0表示不存在,也可以赋予其其他含义
//}
//
//void delt(char *s)          //  只做标记, 假定s一定存在
//{
//    int rt = 0;
//    for (; *s; ++s)
//    {
//        rt = tree[rt][*s - tb];
//    }
//    tree[rt][tk] = 0;
//    return ;
//}
//
//int prefix(char *s)         //  最长前缀
//{
//    int rt = 0, lv;
//    for (lv = 0; *s; ++s, ++lv)
//    {
//        rt = tree[rt][*s - tb];
//        if (rt == 0)
//        {
//            break;
//        }
//    }
//    return lv;
//}

//  左孩子右兄弟

/*
 *  左孩子右兄弟
 *  INIT: init();
 */
const int N = 1010;
int top;
struct trie
{
    char c;
    int l, r, rk;
} tree[N];

void init()
{
    top = 1;
    memset(tree, 0, sizeof(tree[0]));
}

int sear(char *s)   //  失败返回0
{
    int rt;
    for (rt = 0; *s; ++s)
    {
        for (rt = tree[rt].l; rt; rt = tree[rt].r)
        {
            if (tree[rt].c == *s)
            {
                break;
            }
        }
        if (rt == 0)
        {
            return 0;
        }
    }
    return tree[rt].rk;
}

void insert(char *s, int rk = 1)    //  rk: 权或者标记
{
    int i, rt;
    for (rt = 0; *s; ++s, rt = i)
    {
        for (i = tree[rt].l; i; i = tree[i].r)
        {
            if (tree[i].c == *s)
            {
                break;
            }
        }
        if (i == 0)
        {
            tree[top].r = tree[rt].l;
            tree[top].l = 0;
            tree[top].c = *s;
            tree[top].rk = 0;
            tree[rt].l = top;
            i = top++;
        }
    }
    tree[rt].rk = rk;
    return ;
}

void delt(char *s)  //  假定s已经存在,只做标记
{
    int rt;
    for (rt = 0; *s; ++s)
    {
        for (rt = tree[rt].l; rt; rt = tree[rt].r)
        {
            if (tree[rt].c == *s)
            {
                break;
            }
        }
        tree[rt].rk = 0;
    }
    return ;
}

int profix(char *s) //  最长前缀
{
    int rt = 0, lv;
    for (lv = 0; *s; ++s, ++lv)
    {
        for (rt = tree[rt].l; rt; rt = tree[rt].r)
        {
            if (tree[rt].c == *s)
            {
                break;
            }
        }
        if (rt == 0)
        {
            break;
        }
    }
    return lv;
}