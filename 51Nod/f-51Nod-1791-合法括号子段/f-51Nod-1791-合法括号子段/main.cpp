//
//  main.cpp
//  f-51Nod-1791-合法括号子段
//
//  Created by ZYJ on 2017/7/31.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 1e5 + 10;
const int INF = 0x3f3f3f3f;

ll ans;
char s[MAXN];
int mn[MAXN];
int mx[MAXN];
int sum_r[MAXN];
int sum_l[MAXN];
int cnt[MAXN << 1];

void solve(int l, int r)
{
    if (l >= r)
    {
        return ;
    }
    
    int m = (l + r) >> 1;
    solve(l, m);
    solve(m + 1, r);
    
    mn[m] = INF;
    sum_r[m] = 0;
    for (int i = m + 1; i <= r; i++)
    {
        sum_r[i] = sum_r[i - 1] + (s[i] == '(' ? 1 : -1);
        mn[i] = min(mn[i - 1], sum_r[i]);
        if (-mn[i] <= -sum_r[i])    //  控制左区段的合法性
        {
            cnt[-sum_r[i] + MAXN]++;
        }
    }
    
    sum_l[m + 1] = mx[m + 1] = 0;
    for (int i = m; i >= l; i--)
    {
        sum_l[i] = sum_l[i + 1] + (s[i] == '(' ? 1 : -1);
        mx[i] = max(mx[i + 1], sum_l[i]);
        if (sum_l[i] >= mx[i + 1])
        {
            ans += cnt[sum_l[i] + MAXN];
        }
    }
    
    for (int i = m + 1; i <= r; i++)
    {
        if (-mn[i] <= -sum_r[i])    //  重置
        {
            cnt[-sum_r[i] + MAXN]--;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        ans = 0;
        scanf("%s", s + 1);
        int len = (int)strlen(s + 1);
        solve(1, len);
        printf("%lld\n", ans);
    }
    
    return 0;
}
