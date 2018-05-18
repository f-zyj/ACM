//
//  main.cpp
//  f-51Nod-1434-区间LCM
//
//  Created by ZYJ on 16/9/18.
//  Copyright © 2016年 ZYJ. All rights reserved.
//

//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <cmath>
//
//#define rep(i, s, t) for (int i = s; i <= t; i++)
//#define dwn(i, s, t) for (int i = s; i >= t; i--)
//#define clr(x, c) memset(x, c, sizeof(x))
//#define ll long long
//
//using namespace std;
//
//const int MAXN = 1e6 + 5;
//
//int prime[MAXN << 3];
//bool vis[MAXN + 1];
//
//int main()
//{
//    int cnt = 0, tp;
//    rep(i, 2, MAXN)
//    {
//        if (!vis[i])
//        {
//            prime[++cnt] = i;
//        }
//        rep(j, 1, cnt)
//        {
//            tp = prime[j];
//            if ((ll)tp * i > MAXN)
//            {
//                break;
//            }
//            vis[tp * i] = 1;
//            if (i % tp == 0)
//            {
//                break;
//            }
//        }
//    }
//    int T, u, v;
//    scanf("%d", &T);
//    while (T--)
//    {
//        int n;
//        scanf("%d", &n);
//        int ans = n;
//        if (n == 1)
//        {
//            printf("2\n");
//            continue;
//        }
//        rep(i, 1, cnt)
//        {
//            if (prime[i] > n)
//            {
//                break;
//            }
//            tp = 1;
//            u = (int)(log(n) / log(prime[i]));
//            v = (int)pow(prime[i], u);
//            for (int j = 2; ; ++j)
//            {
//                if (v * j > n)
//                {
//                    v *= j;
//                    break;
//                }
//            }
//            ans = max(ans, v);
//        }
//        printf("%d\n", ans);
//    }
//    
//    return 0;
//}

#include <stdio.h>

#define MAXN 1000009
#define MAXP 300000
#define max(a, b) ((a) > (b) ? (a) : (b))

int prime[MAXN];
int p[MAXP];

int main()
{
    int k = 0;
    for (int i = 2; i < MAXN; i++)
    {
        if (!prime[i])
        {
            p[k++] = i;
            for (int j = 2 * i; j < MAXN; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N, g = 1;
        scanf("%d", &N);
        for (int i = 0; p[i] <= N; i++)
        {
            for (int j = p[i]; j <= N; j *= p[i])
            {
                g = max(g, j);
            }
        }
        printf("%d\n", g * 2);
    }
    
    return 0;
}