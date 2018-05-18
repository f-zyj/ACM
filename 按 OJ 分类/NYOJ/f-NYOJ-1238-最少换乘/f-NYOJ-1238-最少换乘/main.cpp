//
//  main.cpp
//  f-NYOJ-1238-最少换乘
//
//  Created by ZYJ on 2017/5/3.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 505;
const int INF = 0x3f3f3f3f;

vector<int> vi[MAXN];
int d[MAXN], vis[MAXN], a[MAXN];
char s[100 * MAXN];

void spfa(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    d[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        vis[u] = 0;
        q.pop();
        for (int i = 0; i < vi[u].size(); i++)
        {
            int v = vi[u][i];
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    
    int n, m;
    while (T--)
    {
        memset(vis, 0, sizeof(vis));
        
        cin >> m >> n;
        getchar();
        for (int i = 1; i <= n; i++)
        {
            d[i] = INF;
            vi[i].clear();
        }
        
        for (int i = 0; i < m; i++)
        {
            fgets(s, 100 * MAXN, stdin);
            int len = (int)strlen(s);
            len--;
            int cnt = 0;
            for (int i = 0; i < len; i++)
            {
                while (s[i] == ' ')
                {
                    i++;
                }
                int num = 0;
                while (s[i] >= '0' && s[i] <= '9')
                {
                    num *= 10;
                    num += s[i] - '0';
                    i++;
                }
                a[cnt++] = num;
            }
            for (int j = 0; j < cnt; j++)
            {
                for (int k = j + 1; k < cnt; k++)
                {
                    vi[a[j]].push_back(a[k]);
                }
            }
        }
        spfa(1);
        if (d[n] == INF)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << d[n] << endl;
        }
    }
    
    return 0;
}
