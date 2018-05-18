//
//  main.cpp
//  f-HDU-2017 多校训练赛10-1008-Monkeys
//
//  Created by ZYJ on 2017/8/28.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 7;

int n, k;
int pd[MAXN];
int vis[MAXN];
vector<int> arr[MAXN];

struct FastIO
{
    static const int S = 100 << 1;
    
    int wpos;
    char wbuf[S];
    
    FastIO() : wpos(0) {}
    
    inline int xchar()
    {
        static char buf[S];
        static int len = 0, pos = 0;
        
        if (pos == len)
        {
            pos = 0;
            len = (int)fread(buf, 1, S, stdin);
        }
        if (pos == len)
        {
            return -1;
        }
        
        return buf[pos++];
    }
    
    inline int xint()
    {
        int s = 1, c = xchar(), x = 0;
        while (c <= 32)
        {
            c = xchar();
        }
        if (c == '-')
        {
            s = -1;
            c = xchar();
        }
        for (; '0' <= c && c <= '9'; c = xchar())
        {
            x = x * 10 + c - '0';
        }
        
        return x * s;
    }
    
    ~FastIO()
    {
        if (wpos)
        {
            fwrite(wbuf, 1, wpos, stdout);
            wpos = 0;
        }
    }
} io;

int main()
{
//    freopen("/Users/zyj/Desktop/input.txt", "r", stdin);
    
    memset(pd, 0, sizeof(pd));
    
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        
        n = io.xint();
        k = io.xint();
        
        for (int i = 1; i <= n; i++)
        {
            arr[i].clear();
        }
        
        int a;
        for (int i = 2; i <= n; i++)
        {
            a = io.xint();
            arr[a].push_back(i);
            arr[i].push_back(a);
            pd[a]++;
            pd[i]++;
        }
        
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (pd[i] == 1)
            {
                q.push(i);
            }
            pd[i] = 0;
        }
        
        int ans = 0;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            
            if (arr[now].size() != 0)
            {
                int v = arr[now][0];
                if (vis[now] == 0 && vis[v] == 0)
                {
                    ans++;
                    vis[now] = 1;
                    vis[v] = 1;
                }
                
                arr[v].erase(remove(arr[v].begin(), arr[v].end(), now),arr[v].end());
                
                if (arr[v].size() == 1)
                {
                    q.push(v);
                }
            }
        }
        
        if (ans * 2 >= k)
        {
            printf("%d\n", (k + 1) / 2);
        }
        else
        {
            printf("%d\n", ans + k - ans * 2);
        }
    }
    
    return 0;
}

