//
//  main.cpp
//  f-51Nod-1610-路径计数
//
//  Created by ZYJ on 2016/10/24.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 101;
const int MAXM = 5e4 + 10;

int n, m;
int a[MAXM];
int b[MAXM];
int c[MAXM];
int dp[MAXN][MAXN][MAXN];
ll tmp[MAXN];
ll res[MAXN];
ll ans[MAXN];

ll dfs(int u, int d)
{
    if (res[u] != -1)
    {
        return res[u];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dp[d][u][i])
        {
            ans = (ans + dp[d][u][i] + dp[d][u][i] * dfs(i, d)) % MOD;
        }
    }
    
    return res[u] = ans;
}

ll cal(int u)
{
    clr(res, -1);
    for (int i = 1; i <= n; i++)
    {
        if (res[i] == -1)
        {
            dfs(i, u);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + res[i]) % MOD;
    }
    
    return ans;
}

int main()
{
    clr(dp, 0);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        for (int j = 1; j * j <= c[i]; j++)
        {
            if (c[i] % j == 0)
            {
                dp[j][a[i]][b[i]]++;
                if (c[i] / j != j)
                {
                    dp[c[i] / j][a[i]][b[i]]++;
                }
            }
        }
    }
    
    for (int i = 1; i < MAXN; i++)
    {
        tmp[i] = cal(i);
    }
    for (int i = MAXN - 1; i > 0; i--)
    {
        ans[i] = tmp[i];
        for (int j = 2 * i; j < MAXN; j += i)
        {
            ans[i] -= ans[j];
        }
        ans[i] = (ans[i] % MOD + MOD) % MOD;
    }
    
    cout << ans[1] << endl;
    
    int T;
    cin >> T;
    while (T--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        vector<int> v;
        for (int i = 1; i * i <= c[x]; i++)
        {
            if (c[x] % i == 0)
            {
                dp[i][a[x]][b[x]]--;
                v.push_back(i);
                if (c[x] / i != i)
                {
                    dp[c[x] / i][a[x]][b[x]]--;
                    v.push_back(c[x] / i);
                }
            }
        }
        c[x] = y;
        for (int i = 1; i * i <= c[x]; i++)
        {
            if (c[x] % i == 0)
            {
                dp[i][a[x]][b[x]]++;
                v.push_back(i);
                if (c[x] / i != i)
                {
                    dp[c[x] / i][a[x]][b[x]]++;
                    v.push_back(c[x] / i);
                }
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            tmp[v[i]] = cal(v[i]);
        }
        for (int i = MAXN - 1; i > 0; i--)
        {
            ans[i] = tmp[i];
            for (int j = 2 * i; j < MAXN; j += i)
            {
                ans[i] -= ans[j];
            }
            ans[i] = (ans[i] % MOD + MOD) % MOD;
        }
        
        cout << ans[1] << endl;
    }
    
    return 0;
}
