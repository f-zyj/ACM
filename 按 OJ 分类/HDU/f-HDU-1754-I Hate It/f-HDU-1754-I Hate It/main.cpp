//
//  main.cpp
//  f-HDU-1754-I Hate It
//
//  Created by ZYJ on 2017/1/10.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXSIZE = 2e5 + 10;

typedef struct
{
    int max;
    int left, right;
} NODE;

int n, m;
int num[MAXSIZE];
NODE tree[MAXSIZE * 4];

//  构建线段树
int build(int root, int left, int right)
{
    int mid;
    
    tree[root].left = left;
    tree[root].right = right;
    
    if (left == right)
    {
        return tree[root].max = num[left];
    }
    mid = (left + right) >> 1;
    
    int a, b;
    a = build(2 * root, left, mid);
    b = build(2 * root + 1, mid + 1, right);
    
    return tree[root].max = max(a, b);
}

//  从节点 root 开始，查找 left 和 right 之间的最大值
int find(int root, int left, int right)
{
    if (tree[root].left > right || tree[root].right < left)
    {
        return 0;
    }
    if (left <= tree[root].left && tree[root].right <= right)
    {
        return tree[root].max;
    }
    
    int a, b;
    a = find(2 * root, left, right);
    b = find(2 * root + 1, left, right);
    
    return max(a, b);
}

//  更新 pos 点的值
int update(int root, int pos, int val)
{
    if (pos < tree[root].left || tree[root].right < pos)
    {
        return tree[root].max;
    }
    
    if (tree[root].left == pos && tree[root].right == pos)
    {
        return tree[root].max = val;
    }
    
    int a, b;
    a = update(2 * root, pos, val);
    b = update(2 * root + 1, pos, val);
    
    tree[root].max = max(a, b);
    
    return tree[root].max;
}

int main ()
{
    char c;     //  这里建议用字符串，这样不用担心缓冲区'\n'等问题
    int x, y;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &num[i]);
        }
        build(1, 1, n);
        
        for (int i = 1; i <= m; ++i)
        {
            getchar();
            scanf("%c%d%d", &c, &x, &y);
            if (c == 'Q')
            {
                printf("%d\n", find(1, x, y));
            }
            else
            {
                num[x] = y;
                update(1, x, y);
            }
        }
    }
    
    return 0 ;
}

