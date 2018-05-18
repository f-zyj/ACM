//
//  main.cpp
//  ICPC Asia Regional Shenyang Online-1001-string string string
//
//  Created by ZYJ on 2017/9/12.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;
const int MAGIC = 26;

class SAM
{
public:
    int n;
    int last, tot;
    char s[MAXN];
    int c[MAXN];
    int q[MAXN];
    int pre[MAXN];
    int cnt[MAXN];
    int len[MAXN];
    int step[MAXN];
    int son[MAXN][MAGIC + 1];
    
    void clear(char *_s)
    {
        n = (int)strlen(_s);
        memcpy(s, _s, sizeof(char) * (n + 5));
        
        int t = (n << 1) + 10;
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < MAGIC; j++)
            {
                son[i][j] = 0;
            }
            pre[i] = step[i] = 0;
        }
        last = tot = 0;
    }
    
    void extend(char ch)
    {
        step[++tot] = step[last] + 1;
        int p = last, np = tot;
        
        for (; !son[p][ch]; p = pre[p])
        {
            son[p][ch] = np;
        }
        if (!p)
        {
            pre[np] = 1;
        }
        else
        {
            int q = son[p][ch];
            if (step[q] == step[p] + 1)
            {
                pre[np] = q;
            }
            else
            {
                step[++tot] = step[p] + 1;
                int nq = tot;
                memcpy(son[nq], son[q], sizeof(son[q]));
                pre[nq] = pre[q];
                pre[q] = pre[np] = nq;
                for (; son[p][ch] == q; p = pre[p])
                {
                    son[p][ch] = nq;
                }
            }
        }
        
        last = np;
        cnt[last]++;
    }
    
    void build()
    {
        int t = (n << 1) + 10;
        for (int i = 0; i < t; i++)
        {
            cnt[i] = 0;
        }
        last = tot = 1;
        for (int i = 0; i < n; i++)
        {
            extend(s[i] - 'a');
        }
    }
    
    void calc(int k)
    {
        int t = (n << 1) + 10;
        for (int i = 0; i < t; i++)
        {
            c[i] = 0;
        }
        for (int i = 1; i <= tot; i++)
        {
            c[step[i]]++;
        }
        for (int i = 1; i <= tot; i++)
        {
            c[i] += c[i - 1];
        }
        for (int i = 1; i <= tot; i++)
        {
            q[c[step[i]]--] = i;
        }
        
        ll ans = 0;
        for (int i = tot; i; i--)
        {
            int u = q[i];
            if (pre[u] > 0)
            {
                cnt[pre[u]]+=cnt[u];
            }
            if (cnt[u] == k)
            {
                ans += step[u] - step[pre[u]];
            }
        }
        
        printf("%lld\n",ans);
    }
} S;

int k;
char s[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        scanf("%d%s", &k, s);
        
        S.clear(s);
        S.build();
        S.calc(k);
    }
    
    return 0;
}
