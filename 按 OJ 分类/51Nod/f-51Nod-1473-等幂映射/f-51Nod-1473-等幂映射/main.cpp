//
//  main.cpp
//  f-51Nod-1473-等幂映射
//
//  Created by ZYJ on 2016/9/25.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//  TLE
//#include <iostream>
//
//using namespace std;
//
//const int MAXN = 201;
//
//int f[MAXN];
//
//int main(int argc, const char * argv[])
//{
//    int n;
//    cin >> n;
//    
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> f[i];
//    }
//    
//    long long k = 1;
//    for (int i = 1; i <= n; i++)
//    {
//        int res = i;
//        for (int j = 0; j < 2 * k; j++)
//        {
//            res = f[res];
//        }
//        int tmp = i;
//        for (int j = 0; j < k; j++)
//        {
//            tmp = f[tmp];
//        }
//        if (res != tmp && i != 1)
//        {
//            k++;
//            i = 0;
//            continue;
//        }
//        if (res == tmp)
//        {
//            continue;
//        }
//        while (res != tmp)
//        {
//            k++;
//            tmp = f[tmp];
//            res = f[f[res]];
//        }
//    }
//    
//    std::cout << k << "\n";
//    return 0;
//}

//#include <cstdio>
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//typedef long long LL;
//
//const int INF = 0x3f3f3f3f;
//const int MAXN = 210;
//
//int vis[MAXN], a[MAXN];
//int N, tot, now;
//LL ans[MAXN];
//
//LL gcd(LL a, LL b)
//{
//    return !b ? a : gcd(b, a % b);
//}
//
//int main ()
//{
//    cin >> N;
//    for (int i = 1; i <= N; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//    for (int i = 1; i <= N; i++)
//    {
//        int j = i;
//        memset(vis, 0, sizeof (vis));
//        vis[j] = 1;
//        while (true)
//        {
//            if (vis[a[j]] == 1)
//            {
//                ans[++tot] = vis[j];
//                break;
//            }
//            if (vis[a[j]] > 1)
//            {
//                now = max(now, vis[a[j]] - 1);
//                break;
//            }
//            vis[a[j]] = vis[j] + 1;
//            j = a[j];
//        }
//    }
//    LL ANS = ans[1];
//    for (int i = 2; i <= tot; i++)
//    {
//        ANS = ANS * ans[i] / gcd(ANS, ans[i]);
//    }
//    LL tmp = ANS;
//    while (ANS < now)
//    {
//        ANS += tmp;
//    }
//    cout << ANS << endl;
//    
//    return 0;
//}


#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAXN 201

typedef long long ll;

int f[MAXN];
int m[MAXN];

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

//  找出每个数字进入循环圈的最小值
//  k能整除每个数字的循环圈
int main()
{
    int n, i, j, next;
    ll tmp;
    ll ans = 1;
    int mink = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", f + i);
    }
    for (i = 1; i <= n; ++i)
    {
        memset(m, 0, sizeof(int) * (n + 1));
        j = i;
        m[f[j]] = 1;
        while (true)
        {
            next = f[j];
            if (m[f[next]])
            {
                tmp = m[f[j]] + 1 - m[f[next]];
                if (mink < m[f[next]])
                {
                    mink = m[f[next]];
                }
                break;
            }
            m[f[next]] = m[f[j]] + 1;
            j = next;
        }
        ans = lcm(ans, tmp);
    }
    
    tmp = ans;
    while (ans < mink)
    {
        ans += tmp;
    }
    printf("%lld\n", ans);
    
    return 0;
}
