//
//  main.cpp
//  f-51Nod-1052-最大M子段和
//
//  Created by ZYJ on 2016/10/10.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 5050;
const int MIN_INF = -0x3f3f3f3f;

ll dp[MAXN];
ll input[MAXN];
ll pre[MAXN];   //  pre[i]:表示从第1个到第i个数被分成x个子段所能得到的最大子段和

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    
    dp[0] = MIN_INF;
    pre[0] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &input[i]);
        pre[i] = 0;
        dp[i] = MIN_INF;
    }
    
    while (m--)
    {
        ll ans = MIN_INF;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                dp[i] = pre[i - 1] + input[i];
            }
            else
            {
                if (dp[i - 1] > pre[i - 1])
                {
                    dp[i] = dp[i - 1] + input[i];   //  第i个数与它的上一个数在同一子段内
                }
                else
                {
                    dp[i] = pre[i - 1] + input[i];  //  从第i个分出一个新的子段
                }
            }
            //  dp[i] = max(dp[i - 1], pre[i - 1]) + input[i]; 或者直接这么取值也可
            pre[i - 1] = ans;
            ans = max(ans, dp[i]);
        }
        pre[n] = ans;
    }
    printf("%lld\n", pre[n]);
    
    return 0;
}
