//
//  main.cpp
//  f-河南第十届ACM省赛-E-八纵八横
//
//  Created by ZYJ on 2017/5/8.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <set>

#define FILE "eights"

using namespace std;

const int MAXN = 1024;

typedef bitset<MAXN> bst;

struct node
{
    int x, next;
    bst v;
} e[MAXN << 1];

char ch[MAXN];
int n, m, P, cnt, len, Link[MAXN], f[MAXN], wh[MAXN], E[MAXN][2];
bst mat[MAXN], M[MAXN], dis[MAXN], V[MAXN];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

bst Read()
{
    bst temp;
    temp.reset();
    scanf("%s", ch + 1);
    int len = (int)strlen(ch + 1);
    for (int i = 1; i <= len; i++)
    {
        temp[len - i] = ch[i] - '0';
    }
    return temp;
}

void insert(int x, int y, bst v)
{
    e[++len].next = Link[x];
    Link[x] = len;
    e[len].x = y;
    e[len].v = v;
    e[++len].next = Link[y];
    Link[y] = len;
    e[len].x = x;
    e[len].v = v;
}

int find(int x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}

void dfs(int x, int pre)
{
    for (int i = Link[x]; i; i = e[i].next)
    {
        if (e[i].x != pre)
        {
            dis[e[i].x] = dis[x] ^ e[i].v;
            dfs(e[i].x, x);
        }
    }
}

void updata(int x, bst y)
{
    int pos = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        if (M[i][x] && mat[i].none())
        {
            pos = i;
            break;
        }
    }
    if (!pos)
    {
        for (int i = 0; i <= 1000; ++i)
        {
            if (M[wh[i]][x] && wh[i] != 0)
            {
                pos = wh[i];
                wh[i] = 0;
                break;
            }
        }
    }
    for (int i = 1; i <= 1000; ++i)
    {
        if (pos != i && M[i][x])
        {
            mat[i] = mat[i] ^ mat[pos], M[i] = M[i] ^ M[pos];
        }
    }
    mat[pos] ^= y;
    for (int i = 1000; i >= 0; --i)
    {
        if (mat[pos][i])
        {
            if (!wh[i])
            {
                wh[i] = pos;
                break;
            }
            else
            {
                mat[pos] = mat[pos] ^ mat[wh[i]];
                M[pos] = M[pos] ^ M[wh[i]];
            }
        }
    }
}

void output()
{
    bst ans;
    ans.reset();
    char ts[MAXN], *tmp;
    for (int i = 1000; i >= 0; --i)
    {
        if (ans[i] == 0 && wh[i])
        {
            ans = ans ^ mat[wh[i]];
        }
    }
    if (ans.none())
    {
        puts("0");
    }
    else
    {
        tmp = ts;
        for (int i = 1000; i >= 0; --i)
        {
            if (ans[i])
            {
                for (int j = i; j >= 0; --j)
                {
                    *(tmp++) = ans[j] + '0';
                }
                break;
            }
        }
        *(tmp++) = '\0';
        puts(ts);
    }
}

int main()
{
//    freopen(FILE".in", "r", stdin);
//    freopen(FILE".out", "w", stdout);

    n = read();
    m = read();
    P = read();
    for (int i = 1; i <= n; ++i)
    {
        f[i] = i;
    }
    for (int i = 1; i <= 1000; ++i)
    {
        M[i][i] = 1;
    }
    for (int i = 1; i <= m; ++i)
    {
        int x = read(), y = read();
        bst value = Read();
        if (find(x) == find(y))
        {
            E[++cnt][0] = x, E[cnt][1] = y, V[cnt] = value;
        }
        else
        {
            f[find(x)] = find(y), insert(x, y, value);
        }
    }
    dfs(1, 0);
    int CASE = cnt;
    for (int i = 1; i <= cnt; ++i)
    {
        updata(i, dis[E[i][0]] ^ dis[E[i][1]] ^ V[i]);
    }
    output();
    for (int i = 1; i <= P; ++i)
    {
        char opt[10];
        scanf("%s", opt);
        if (opt[1] == 'd')
        {
            int x = read(), y = read();
            bst value = Read();
            E[++cnt][0] = x;
            E[cnt][1] = y;
            V[cnt] = value;
            updata(cnt, dis[E[cnt][0]] ^ dis[E[cnt][1]] ^ V[cnt]);
        }
        else if (opt[1] == 'h')
        {
            int x = read();
            bst value = Read();
            updata(x + CASE, V[x + CASE] ^ value);
            V[x + CASE] = value;
        }
        else
        {
            int x = read();
            updata(x + CASE, dis[E[x + CASE][0]] ^ dis[E[x + CASE][1]] ^ V[x + CASE]);
            V[x + CASE] = dis[E[x + CASE][0]] ^ dis[E[x + CASE][1]];
        }
        output();
    }
    
    return 0;
}
