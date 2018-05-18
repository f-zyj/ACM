//
//  main.cpp
//  f-51Nod-1398-等公交
//
//  Created by ZYJ on 2017/6/21.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <cstring>

#define clr(a, b) memset(a, b, sizeof(a))

using namespace std;

const int MAXN = 100;
const int MAXS = 2e5 + 5;

int N, s;
int tim[MAXN];
double pro[MAXN];
double dp[MAXS];

int main ()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        clr(dp, 0);
        dp[0] = 1;
        
        scanf("%d%d", &N, &s);
        for (int i = 0; i < N; i++)
        {
            scanf("%d%lf", tim + i, pro + i);
            pro[i] /= MAXN;
        }
        
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dp[i + tim[j]] += dp[i] * pro[j];
            }
        }
        
        double ans = 0;
        for (int i = s + 1; i < MAXS; i++)
        {
            ans += (i - s) * dp[i];
        }
        
        printf("%.4lf\n", ans);
    }
    
    return 0;
}
