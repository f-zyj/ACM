//
//  main.cpp
//  f-HDU-1512-Monkey King
//
//  Created by ZYJ on 2017/10/27.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 10;

struct node
{
    int key, dis;
    int lson, rson;
    int pre;
} Tree[MAXN];

int n, q;

void init(int p, int k)
{
    Tree[p].key = k;
    Tree[p].pre = p;
    Tree[p].lson = Tree[p].rson = 0;
    Tree[p].dis = p == 0 ? -1 : 0;
}

int find(int x)
{
    if (Tree[x].pre == x)
    {
        return x;
    }
    else
    {
        return find(Tree[x].pre);
    }
}

int merge(int x, int y)
{
    if (x == 0)
    {
        return y;
    }
    if (y == 0)
    {
        return x;
    }
    
    if (Tree[x].key < Tree[y].key)
    {
        swap(x, y);
    }
    Tree[x].rson = merge(Tree[x].rson, y);
    int &ls = Tree[x].lson, &rs = Tree[x].rson;
    Tree[ls].pre = Tree[rs].pre = x;
    if (Tree[ls].dis < Tree[rs].dis)
    {
        swap(ls, rs);
    }
    if (rs == 0)
    {
        Tree[x].dis = 0;
    }
    else
    {
        Tree[x].dis = Tree[rs].dis + 1;
    }
    
    return x;
}

int del(int x)
{
    int ls = Tree[x].lson;
    int rs = Tree[x].rson;
    Tree[ls].pre = ls;
    Tree[rs].pre = rs;
    Tree[x].dis = Tree[x].lson = Tree[x].rson = 0;
    return merge(ls, rs);
}

int solve(int x, int y)
{
    Tree[x].key >>= 1;
    Tree[y].key >>= 1;
    
    int _x = del(x), _y = del(y);
    _x = merge(x, _x);
    _y = merge(y, _y);
    x = merge(_x, _y);
    return Tree[x].key;
}

int main(int argc, const char * argv[])
{
    while (cin >> n)
    {
        int x;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            init(i, x);
        }
        init(0, 0);
        
        cin >> q;
        int y;
        while (q--)
        {
            scanf("%d%d", &x, &y);
            int _x = find(x), _y = find(y);
            if (_x == _y)
            {
                puts("-1");
            }
            else
            {
                printf("%d\n", solve(_x, _y));
            }
        }
    }
    
    return 0;
}
