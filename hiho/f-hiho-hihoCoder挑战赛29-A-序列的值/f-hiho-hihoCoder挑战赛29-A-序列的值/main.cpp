//
//  main.cpp
//  f-hiho-hihoCoder挑战赛29-A-序列的值
//
//  Created by ZYJ on 2017/6/25.
//  Copyright © 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;
const int MAX_DIG = 31;
const int MOD = 998244353;

int n, ans = 0;
int a[MAXN];
int power[MAXN];
int c[MAX_DIG + 3][2];

void init()
{
    power[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        power[i] = (ll)power[i - 1] * 2 % MOD;
    }
}

int main()
{
    scanf("%d", &n);
    
    init();
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i <= MAX_DIG; i++)
    {
        c[i][0] = 1;
    }
    
    for (int i = 1, j; i <= n; i++)
    {
        for (j = MAX_DIG; j >= 0; j--)
        {
            if (a[i] & (1 << j))
            {
                break;
            }
        }
        ans += (ll)c[j][0] * power[n - i] % MOD;
        ans %= MOD;
        
        for (j = 0; j <= MAX_DIG; j++)
        {
            int t0 = c[j][0];
            int t1 = c[j][1];
            if (a[i] & (1 << j))
            {
                c[j][0] = (t0 + t1) % MOD;  //  选 a[i] 的有 t1 种 不选 a[i] 的有 t0 种
                c[j][1] = (t0 + t1) % MOD;  //  选 a[i] 的有 t0 种 不选 a[i] 的有 t1 种
            }
            else
            {
                c[j][0] = t0 * 2 % MOD;     //  选或不选 a[i] 都是 t0 种
                c[j][1] = t1 * 2 % MOD;     //  选或不选 a[i] 都是 t1 种
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
