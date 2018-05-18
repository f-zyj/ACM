//
//  main.cpp
//  f-51Nod-1574-排列转换
//
//  Created by ZYJ on 2017/5/19.
//  Copyright ? 2017年 ZYJ. All rights reserved.
//

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int A[MAXN];
int B[MAXN];
bool vis[MAXN];

int abs(int a)
{
    return a < 0 ? -a : a;
}

int main ()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", A + i);
    }
    int b;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b);
        B[b] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        A[i] = B[A[i]];
    }
    
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        ll sum = 0;
        for (int j = i; !vis[j]; j = A[j])
        {
            sum += abs(j - A[j]);
            vis[j] = true;
        }
        ans += sum / 2;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
