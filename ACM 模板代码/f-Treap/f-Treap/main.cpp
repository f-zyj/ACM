//
//  main.cpp
//  f-Treap
//
//  Created by ZYJ on 16/7/21.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

const int MAXN = 300010;
int num[MAXN], st[MAXN];

struct Treap
{
    int tot1;
    int s[MAXN], tot2;  //  内存池和容量
    int ch[MAXN][2];
    int key[MAXN], size[MAXN];
    int sum0[MAXN], sum1[MAXN];
    int status[MAXN];
    
    void Init()
    {
        tot1 = tot2 = 0;
        size[0] = 0;
        ch[0][0] = ch[0][1] = 0;
        sum0[0] = sum1[0] = 0;
        return ;
    }
    bool random(double p)
    {
        return (double)rand() / RAND_MAX < p;
    }
    int newnode(int val, int _status)
    {
        int r;
        if (tot2)
        {
            r = s[tot2--];
        }
        else
        {
            r = ++tot1;
        }
        size[r] = 1;
        key[r] = val;
        status[r] = _status;
        ch[r][0] = ch[r][1] = 0;
        sum0[r] = sum1[r] = 0;  //  需要push_up
        return r;
    }
    void del(int r)
    {
        if (!r)
        {
            return ;
        }
        s[++tot2] = r;
        del(ch[r][0]);
        del(ch[r][1]);
        return ;
    }
    void push_up(int r)
    {
        int lson = ch[r][0], rson = ch[r][1];
        size[r] = size[lson] + size[rson] + 1;
        sum0[r] = (int)gcd(sum0[lson], sum0[rson]);
        sum1[r] = (int)gcd(sum1[lson], sum1[rson]);
        if (status[r] == 0)
        {
            sum0[r] = (int)gcd(sum0[r], key[r]);
        }
        else
        {
            sum1[r] = (int)gcd(sum1[r],key[r]);
        }
        return ;
    }
    void merge(int &p, int x, int y)
    {
        if (!x || !y)
        {
            p = x | y;
        }
        else if (random((double)size[x] / (size[x] + size[y])))
        {
            merge(ch[x][1], ch[x][1], y);
            push_up(p = x);
        }
        else
        {
            merge(ch[y][0], x, ch[y][0]);
            push_up(p = y);
        }
        return ;
    }
    void split(int p, int &x, int &y, int k)
    {
        if (!k)
        {
            x = 0;
            y = p;
            return ;
        }
        if (size[ch[p][0]] >= k)
        {
            y = p;
            split(ch[p][0], x, ch[y][0], k);
            push_up(y);
        }
        else
        {
            x = p;
            split(ch[p][1], ch[x][1], y, k - size[ch[p][0]] - 1);
            push_up(x);
        }
        return ;
    }
    void build(int &p, int l, int r)
    {
        if (l > r)
        {
            return ;
        }
        int mid = (l + r) / 2;
        p = newnode(num[mid], st[mid]);
        build(ch[p][0], l, mid - 1);
        build(ch[p][1], mid + 1, r);
        push_up(p);
        return ;
    }
    void debug(int root)
    {
        if (root == 0)
        {
            return ;
        }
        printf("%d 左儿子:%d 右儿子: %d size = %d key = %d\n", root, ch[root][0], ch[root][1], size[root], key[root]);
        debug(ch[root][0]);
        debug(ch[root][1]);
    }
};

Treap T;
char op[10];

int main()
{
    //  freopen("in.txt", "r", stdin);
    //  freopen("out.txt", "w", stdout);
    int n, q;
    while (scanf("%d%d", &n, &q) == 2)
    {
        int root = 0;
        T.Init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &num[i], &st[i]);
        }
        T.build(root, 1, n);
        while (q--)
        {
            scanf("%s", op);
            if (op[0] == 'Q')
            {
                int l, r, s;
                scanf("%d%d%d", &l, &r, &s);
                int x, y, z;
                T.split(root, x, z, r);
                T.split(x, x, y, l - 1);
                if (s == 0)
                {
                    printf("%d\n", T.sum0[y] == 0 ? -1 : T.sum0[y]);
                }
                else
                {
                    printf("%d\n", T.sum1[y] == 0 ? -1 : T.sum1[y]);
                }
                T.merge(x, x, y);
                T.merge(root, x, z);
            }
            else if (op[0] == 'I')
            {
                int v, s, loc;
                scanf("%d%d%d", &loc, &v, &s);
                int x, y;
                T.split(root, x, y, loc);
                T.merge(x, x, T.newnode(v,s));
                T.merge(root, x, y);
            }
            else if (op[0] == 'D')
            {
                int loc;
                scanf("%d", &loc);
                int x, y, z;
                T.split(root, x, z, loc);
                T.split(x, x, y, loc - 1);
                T.del(y);
                T.merge(root, x, z);
            }
            else if(op[0] == 'R')
            {
                int loc;
                scanf("%d", &loc);
                int x, y, z;
                T.split(root, x, z, loc);
                T.split(x, x, y, loc - 1);
                T.status[y] = 1 - T.status[y];
                T.push_up(y);
                T.merge(x, x, y);
                T.merge(root, x, z);
            }
            else
            {
                int loc, v;
                scanf("%d%d", &loc, &v);
                int x, y, z;
                T.split(root, x, z, loc);
                T.split(x, x, y, loc - 1);
                T.key[y] = v;
                T.push_up(y);
                T.merge(x, x, y);
                T.merge(root, x, z);
            }
        }
    }
    return 0;
}
