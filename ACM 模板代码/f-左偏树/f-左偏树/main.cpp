//
//  main.cpp
//  f-左偏树
//
//  Created by ZYJ on 16/7/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

using namespace std;

//  左偏树

/*
 *  合并复杂度 O(log N)
 *  INIT: init()读入数据并进行初始化;
 *  CALL: merge() 合并两棵左偏树; 
 *        ins() 插入一个新节点; 
 *        top() 取得最小结点; 
 *        pop() 取得并删除最小结点; 
 *        del() 删除某结点;
 *        add() 增/减一个结点的键值;
 *        iroot() 获取结点i的根;
 */
#define typec int       //  type of key val
const int na = -1;
const int N = 1010;

struct node
{
    typec key;
    int l, r, f, dist;
} tr[N];

int iroot(int i)
{   //  find i's root
    if (i == na)
    {
        return i;
    }
    while (tr[i].f != na)
    {
        i = tr[i].f;
    }
    return i;
}

int merge(int rx, int ry)
{
    //  two root:   rx, ry
    if (rx == na)
    {
        return ry;
    }
    if (ry == na)
    {
        return rx;
    }
    if (tr[rx].key > tr[ry].key)
    {
        swap(rx, ry);
    }
    int r = merge(tr[rx].r, ry);
    tr[rx].r = r;
    tr[r].f = rx;
    if (tr[r].dist > tr[tr[rx].l].dist)
    {
        swap(tr[rx].l, tr[rx].r);
    }
    if (tr[rx].r == na)
    {
        tr[rx].dist = 0;
    }
    else
    {
        tr[rx].dist = tr[tr[rx].r].dist + 1;
    }
    return rx;  //  return new root
}

int ins(int i, typec key, int root)
{   //  add a new node(i, key)
    tr[i].key = key;
    tr[i].l = tr[i].r = tr[i].f = na;
    tr[i].dist = 0;
    return root = merge(root, i);   //  return new root
}

int del(int i)
{   //  delete node i
    if (i == na)
    {
        return i;
    }
    int x, y, l, r;
    l = tr[i].l;
    r = tr[i].r;
    y = tr[i].f;
    tr[i].l = tr[i].r = tr[i].f = na;
    tr[x = merge(l, r)].f = y;
    if (y != na && tr[y].l == i)
    {
        tr[y].l = x;
    }
    if (y != na && tr[y].r == i)
    {
        tr[y].r = x;
    }
    for (; y != na; x = y, y = tr[y].f)
    {
        if (tr[tr[y].l].dist < tr[tr[y].r].dist)
        {
            swap(tr[y].l, tr[y].r);
        }
        if (tr[tr[y].r].dist + 1 == tr[y].dist)
        {
            break;
        }
        tr[y].dist = tr[tr[y].r].dist + 1;
    }
    if (x != na)    //  return new root
    {
        return iroot(x);
    }
    else return iroot(y);
}

node top(int root)
{
    return tr[root];
}

node pop(int &root)
{
    node out = tr[root];
    int l = tr[root].l, r = tr[root].r;
    tr[root].l = tr[root].r = tr[root].f = na;
    tr[l].f = tr[r].f = na;
    root = merge(l, r);
    return out;
}

int add(int i, typec val)   //  tr[i].key += val
{
    if (i == na)
    {
        return i;
    }
    if (tr[i].l == na && tr[i].r == na && tr[i].f == na)
    {
        tr[i].key += val;
        return i;
    }
    typec key = tr[i].key + val;
    int rt = del(i);
    return ins(i, key, rt);
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tr[i].key);    //  %d: type of key
        tr[i].l = tr[i].r = tr[i].f = na;
        tr[i].dist = 0;
    }
    return ;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
